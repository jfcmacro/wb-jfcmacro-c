#include <iostream>
#include <stdlib.h>

using namespace std;

#define bint unsigned int
#define u32 unsigned int
#define u16 unsigned short
#define u8 unsigned char

class BigInteger {

	u8* data;
	u32 maxSize;
	u32 offset;
	u32 blockSize;
	
	public:
		BigInteger(u8* data, u32 maxSize, u32 offset){
			this->data = data;
			this->maxSize = maxSize;
			this->offset = offset;
			blockSize = 8;
		}
		
		//print this
		void print();
		
		//compare this with other biginteger
		int compare(BigInteger &other);
		
		//finds log2 of this biginteger
		u32 log2();
		
		// set position bit = 1
		void setBit(u32 position);

		// this  >> 1
		void rightShiftOne();
		
		// increment this in 1
		void increment();

		//this = x << shift
		void leftShift(BigInteger &x, u32 shift);
		
		//this = this - other
		void subtract(BigInteger &other);
		
		//this = x / y
		void divide(BigInteger &x, BigInteger &y) ;
		
		
};


//this = x / y
void BigInteger::divide(BigInteger &x, BigInteger &y) {

	u32 logy = y.log2();

	
	u32 yshtmpsize = x.maxSize+2;//+2 por el desbordamiento
	u8 yshtmpdata[yshtmpsize];
	for(int i = 0; i < yshtmpsize; i++){
		yshtmpdata[i] = 0;
	}
	
	
	BigInteger yshtmp(yshtmpdata,yshtmpsize,0);
	
	
	
	while( x.compare(y) > 0 ){

		u32 logx = x.log2();

		u32 tmp = logx - logy;

		//cout << "logx " << logx << endl;
		//cout << "logy " << logy << endl;
		//cout << "tmp " << tmp << endl;
		
		
//		yshtmp = (y << tmp)
		yshtmp.leftShift(y,tmp);
		
//		if (x < (y << tmp)) {
//			tmp--;
//		}

		
		//cout << " x "; x.print();
		//cout << " yshtmp "; yshtmp.print();
		
		if(x.compare(yshtmp) < 0 && tmp > 0){
			yshtmp.rightShiftOne();
		//	cout << " rollback " << endl;
		//	cout << " yshtmp "; yshtmp.print();
			//(y >> 1) esto seria semejante a y << tmp-1
			tmp--;
		//	cout << "tmp " << tmp << endl;
		}

		//cout << " cicle " << endl;

		this->setBit(tmp);
		//result = result | (1 << tmp);
		//cout << " result "; this->print();
		
		x.subtract(yshtmp);
		//x = (x - (y << tmp));
		
	}

	if (x.compare(y) == 0) {
		//result = result + 1;
		increment();
	}

	
	
}


//this = this - other
void BigInteger::subtract(BigInteger &other){


//void substract(u8* x, u32 &xsize, u8* y, u32 ysize){
	//x = (x - (y << tmp));
	
	u16 dif = 0;
	u32 xindex = other.offset;
	u32 yindex = 0;
	
        // resta lo comun
        while(yindex < other.offset) {
		dif = data[yindex] - (other.data[yindex] + (dif >> 15));
		data[yindex] = (u8)dif;
		yindex++;
        }

	// hace el acarreo
        bool borrow = (dif >> 15);
        while (xindex < offset && borrow){
		dif = data[xindex] - 1;
		data[xindex] =(u8)dif;
		borrow = (dif >> 15);
		xindex++;
	}
	
	
	while((offset > 0) && (data[offset-1] == 0 )  ){
		offset--;
	}

}

//this = x << shift
void BigInteger::leftShift(BigInteger &x, u32 shift){

//void lsh(u8* x, u32 xsize, u32 shifting, u8* result, u32 &resultsize){
//(y << tmp)

	if(shift == 0){
		//just copy it
		if(this->offset >= x.offset || this->maxSize >= x.offset){
			this->offset = x.offset;
			u32 index = 0;
			while(index < this->offset){
				this->data[index] = x.data[index];
				index++;
			}
			return;
		}else{
			cout << " value too big to hold in this object " << endl;
			exit(1);
		}
		
	}	


	u32 shiftresultsize = (shift / blockSize) + x.offset;
	
	if(this->maxSize < shiftresultsize){
		cout << "error en shifting will overflow" << endl;
		exit(1);
	}
	
	this->offset = shiftresultsize;
	
	u8 *datasource;
	
	// bit level shift
	
	u32 bitlevelshifting = shift % blockSize;
	if(bitlevelshifting > 0){		
		u32 tmpindex = 0;
		u32 inverseshift = blockSize - bitlevelshifting;
		u8 next = 0;
		while(tmpindex < x.offset){			
			this->data[tmpindex] = x.data[tmpindex] << bitlevelshifting | next;
			next = x.data[tmpindex] >> inverseshift;
			tmpindex++;
		}
		if(next != 0){
			this->offset++;
		}
		this->data[tmpindex] = next;
		//result must be 1 unitsize larger than x
		shift = shift - bitlevelshifting;
		//now the datasource is result
		datasource = this->data;
	}else{
		//the data source is x
		datasource = x.data;
	}
	
		
	if(shift >= blockSize){	
		//corrimiento de bytes
		u32 resultindex = this->offset;

		u32 srcindex = resultindex - (shift / blockSize);
		
		while(srcindex > 0){
			resultindex--;
			srcindex--;
			this->data[resultindex] = datasource[srcindex];
		}
		while(resultindex > 0){
			resultindex--;
			this->data[resultindex] = 0;
		}
	}
}

// increment this in 1
void BigInteger::increment(){

	u32 tmpindex = 0;

		
	while(tmpindex < this->offset){
		if( ((this->data[tmpindex] & 0x80) != 0) & (((++this->data[tmpindex]) & 0x80) == 0)  )  {
			//will carry
			tmpindex++;
			if(tmpindex == this->offset){
				//will carry beyond the offset 
				if( this->offset < this->maxSize){
					//and there is space, so go on
					this->offset++;
				}else{
					//sorry, no more space
					cout << " BigInteger::increment() this->offset >= this->maxSize " << endl;
					exit(1);
				}
			}
			
			
		}else{
			tmpindex = this->offset;
		}
	}

}

// this  >> shift
void BigInteger::rightShiftOne(){

	u8 adjust = 0x00;
	u8 block;
	
	u32 tmpsize = this->offset;
	
	while(tmpsize > 0){
		tmpsize--;
		block = this->data[tmpsize];
		this->data[tmpsize] = block >> 1 | adjust;
		adjust = (block & 0x01) << 7;
	}
	
	if(this->data[this->offset-1] == 0){
		this->offset--;
	}

}

// set position bit = 1
void BigInteger::setBit(u32 position){

	//result = result | (1 << tmp);

	if((position/blockSize) >= this->offset){
		if((position/blockSize) > this->maxSize){
			cout << "error, BigInteger::setbit(u32 position), position >= this->maxSize" << endl;
			cout << " position " << position << endl;
			cout << " blocksize " << blockSize << endl;
			cout << " (position/blockSize) " << (position/blockSize) << endl;
			cout << " this->maxSize " << this->maxSize << endl;
			exit(1);
		}else{
			this->offset = (position/blockSize) + 1;
		}
	}

	u32 index = (position / blockSize);
	position = position - (index*blockSize);
	
	this->data[index] = this->data[index] | (1 << position );
	
	
	
}



//finds log2 of this biginteger
u32 BigInteger::log2(){
//array is:  	byte[0] = l
//		byte[n] = h	

	u8 high = this->data[this->offset-1];

	u32 logaritmo = 0;
	while (high > 0) {
		high >>= 1;
		logaritmo++;
	}
	
	return (logaritmo - 1)+((this->offset-1)*blockSize);
}


//print this
void BigInteger::print(){
	u32 offset = this->offset;
	printf(" maxSize=%2d offset=%2d data=0x",maxSize,offset);
	while(offset > 0){
		offset--;
		printf("%02x",data[offset]);
	}
	printf("\n");
}

//compare this with other biginteger
int BigInteger::compare(BigInteger &other){


	if(this->offset > other.offset){
		return 1;
	}else if(this->offset < other.offset){
		return -1;
	}

	//here xsize = ysize
	u32 tmpindex = this->offset;
	
	while(tmpindex > 0){
		tmpindex--;
		if(this->data[tmpindex] > other.data[tmpindex]){
			return 1;
		}else if(this->data[tmpindex] < other.data[tmpindex]){
			return -1;
		}
	}
	
	return 0;
}




