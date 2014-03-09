public class Control {
	
	public static void main(String args[]) {
		
		Semaforo s = new Semaforo(1);
		
		Thread t1 = new Thread(new Trabajador(s, 2));
		Thread t2 = new Thread(new Trabajador(s, 1));
		
		t1.start();
		t2.start();
	}
}