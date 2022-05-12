import java.util.Comparator;

public class ShapeComparator implements Comparator<Shape> {

	// override the compare() method
	public int compare(Shape s1, Shape s2) {
		return s1.getName().compareTo(s2.getName());
	}

}
