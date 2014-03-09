
public class Trabajador implements Runnable {
	Semaforo s;
	int tiempo;
	
	public Trabajador(Semaforo s, int t) {
			this.s = s;
			this.tiempo = t;
	}
	
	public void run() {
		
		while (true) {
			
			try {
				s.esperar();
				// Sección crítica
				System.out.println("Estoy en seccion critica " +
						Thread.currentThread());
				s.señal();
				System.out.println("Estoy saliendo");
				try {
					Thread.sleep(tiempo);
					System.out.println("Estoy saliendo" + Thread.currentThread());
				} catch (InterruptedException ie) { }
			}
			catch (InterruptedException ie) { } 
		}
	}
}