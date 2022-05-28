import java.util.Comparator;

public interface Shape extends NamedObject {
	public double getPerimeter();

	public double getArea();

	// Shape Name Comparator
	public static Comparator<Shape> nameComparator = new Comparator<Shape>() {

		public int compare(Shape s1, Shape s2) {

			return s1.getName().compareTo(s2.getName());
		}
	};
	
	// Area comparator
	public static Comparator<Shape> areaComparator = new Comparator<Shape>() {

		public int compare(Shape s1, Shape s2) {

			double area1 = s1.getArea();
			double area2 = s2.getArea();

			return (int) (area1 - area2);	//from smallest to greatest

		}
	};
}
