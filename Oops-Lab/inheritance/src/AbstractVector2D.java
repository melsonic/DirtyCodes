public abstract class AbstractVector2D {
	protected float x, y;
	
	public AbstractVector2D(float x, float y) {
		this.x = x;
		this.y = y;
	}
	
	// Override/define these in subclass.
	public abstract String toString();
	public abstract void add(AbstractVector2D v);
	public abstract void sub(AbstractVector2D v);
	public abstract void mul(AbstractVector2D v);
	public abstract void div(AbstractVector2D v) throws ArithmeticException;
}
