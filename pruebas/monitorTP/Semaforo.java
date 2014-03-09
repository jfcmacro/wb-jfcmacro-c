
public class Semaforo {
	
	private int value;
		
	public Semaforo(int value) {
		
		if (value < 0) 
			throw new RuntimeException();
		this.value = value;
		
	}
	
	public synchronized void esperar() throws InterruptedException{
		
		System.out.println("Espera Entro: " + value);
		value--;
		
		while (value < 0)
			wait();
		
		System.out.println("Espera Salio: " + value);
	}
	
	public synchronized void señal() {
		
		System.out.println("señal Entra: " + value);
		value++;
		
		if (value <= 0) {
			notifyAll();
		}
		System.out.println("señal Salio: " + value);
	}
}