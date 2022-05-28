
public class Circle extends PrintableObject implements Shape {
	private double radius;
	private String name;

	public Circle() {
		// TODO Auto-generated constructor stub
	}

	public Circle(double radius) {
		this.radius = radius;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return getName() + "," + this.radius;
	}

	@Override
	public String getName() {
		// TODO Auto-generated method stub
		return this.name.toUpperCase();
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		return 2 * Math.PI * this.radius;
	}

	@Override
	public double getArea() {

		// TODO Auto-generated method stub
		return Math.PI * (this.radius * this.radius);
	}

	public double getRadius() {
		return radius;
	}

	public void setRadius(double radius) {
		this.radius = radius;
	}

	public static Circle parse(String[] input) throws NullPointerException, ArrayIndexOutOfBoundsException {
		
		Circle c1 = new Circle();

		c1.name = input[0];
		c1.setRadius(Double.parseDouble(input[1]));

		return c1;
	}
}
