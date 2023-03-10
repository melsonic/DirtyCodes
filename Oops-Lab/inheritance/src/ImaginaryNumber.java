public class ImaginaryNumber extends AbstractVector2D {
  public ImaginaryNumber(float re, float im) {
    super(re, im); // initializes the superclass by calling its constructor
  }

  public String toString() {
    String a = x + " + i" + y;
    String b = x + " - i" + -y;
    return y<0 ? b : a;
  }

  public void add(AbstractVector2D inum) {
    this.x += inum.x;
    this.y += inum.y;
  }

  public void sub(AbstractVector2D inum) {
    this.x -= inum.x;
    this.y -= inum.y;
  }

  public void mul(AbstractVector2D inum) {
    this.x = this.x*inum.x - this.y*inum.y;
    this.y = this.x*inum.y + this.y*inum.x;
  }

  public void div(AbstractVector2D inum) throws ArithmeticException {
    if(inum.x==0 && inum.y ==0) throw new ArithmeticException("can't divide by 0");
    float div = (inum.x*inum.x) + (inum.y*inum.y);
    this.x = (this.x*inum.x + this.y*inum.y)/div;
    this.y = (this.y*inum.x - this.x*inum.y)/div;
  }

}
