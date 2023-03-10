public class Complex {
  
  private float r, i;

  /**
   * @param r
   * @param i
   */
  Complex(float r, float i) {
    this.r = r;
    this.i = i;
  }

  /**
   * @param a
   * @param b
   * @return
   */
  public static Complex addition(Complex a, Complex b) {
    float ar = a.r, ai = a.i;
    float br = b.r, bi = b.i;
    return new Complex(ar+br, ai+bi);
  }

  /**
   * @param a
   * @param b
   * @return
   */
  public static Complex subtraction(Complex a, Complex b) {
    float ar = a.r, ai = a.i;
    float br = b.r, bi = b.i;
    return new Complex(ar-br, ai-bi);
  }

  /**
   * @param a
   * @param b
   * @return
   */
  public static Complex multiply(Complex a, Complex b) {
    float ar = a.r, ai = a.i;
    float br = b.r, bi = b.i;
    return new Complex(ar*br - ai*bi, ar*bi + ai*br);
  }

  /**
   * @param a
   * @param b
   * @return
   */
  public static Complex division(Complex a, Complex b) throws ArithmeticException {
    float br = b.r, bi = b.i;
    if(br == 0 && bi == 0) throw new ArithmeticException("can't devide by 0");
    Complex up = multiply(a, new Complex(br, -bi));
    Complex down = multiply(b, new Complex(br, -bi));
    return new Complex(up.r/down.r, up.i/down.r);
  }

  /* (non-Javadoc)
   * @see java.lang.Object#toString()
   */
  @Override
  public String toString() {
    String str = this.r + " + i*(" + this.i+")";
    return str;
  }

  public static void main(String[] args) {
        Complex a = new Complex(2, 5);
        Complex b = new Complex(4, 7);
        // System.out.println("a : " + a.toString() + "\n");
        // System.out.println("b : " + b.toString() + "\n");
        System.out.println("add : " + addition(a, b).toString());
        System.out.println("sub : " + subtraction(a, b).toString());
        System.out.println("mul : " + multiply(a, b).toString());
        try {
            System.out.println("div : " + division(a, b).toString());
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }

}
