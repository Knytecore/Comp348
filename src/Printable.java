
public interface Printable {
	public void print();
	public static void print(Object obj) {
		if(obj instanceof Printable) {
			((Printable) obj).print();
		}
	};
	
}
