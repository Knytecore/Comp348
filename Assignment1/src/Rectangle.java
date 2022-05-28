
public class Rectangle extends PrintableObject implements Shape {

	private double large;
	private double length;
	private String name;
	public Rectangle() {
		// TODO Auto-generated constructor stub
	}
	public Rectangle(double large, double length) {
		this.large = large;
		this.length = length;
		// TODO Auto-generated constructor stub
	}
	public double getLarge() {
		return large;
	}

	public double getLength() {
		return length;
	}

	public void setLarge(double large) {
		this.large = large;
	}

	public void setLength(double length) {
		this.length = length;
	}

		@Override
	public String getName() {
		// TODO Auto-generated method stub
		return this.name;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return (2 * this.large + 2 * this.length);
	}

	@Override
	public double getArea() {
	
		return length*large;
	}
	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return this.getName() +"," + this.large + ","+this.length;
	}
	public static Rectangle parse(String[] input) throws NullPointerException, ArrayIndexOutOfBoundsException{

		Rectangle r1 = new Rectangle();
		r1.name = input[0];
		r1.setLarge(Double.parseDouble(input[1]));
		r1.setLength(Double.parseDouble(input[2]));
		return r1;
	}

}
