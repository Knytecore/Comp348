
abstract class PrintableObject implements NamedObject, Printable {

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return this.getName();
	}
	@Override
	public void print() {
	System.out.println(this.toString());
		
	}
}
