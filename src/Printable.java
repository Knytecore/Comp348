
public interface Printable {
	public void print();
	public static void print(Object... obj) {
		for (Object printableobj : obj) {
			if(printableobj instanceof Printable) {
				((Printable) printableobj).print();
			}			
		}

	};
	
}
