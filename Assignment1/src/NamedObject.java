
public interface NamedObject {

	public default String getName(Object obj) {
		
		return obj.getClass().getSimpleName();
	}
	public String getName();
}
