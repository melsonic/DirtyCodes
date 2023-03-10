public class Tester {
	
	public void imaginaryTest() {
		
		System.out.println("Addition test");
		ImaginaryNumber i1 = new ImaginaryNumber(1, 2);
		ImaginaryNumber i2 = new ImaginaryNumber(3, 4);
		System.out.println("Imaginary number i1 = " + i1.toString());
		System.out.println("Imaginary number i2 = " + i2.toString());
		i1.add(i2);
		System.out.println("i1 after addition = " + i1.toString());
    i1.sub(i2);
    System.out.println("i1 after subtraction = " + i1.toString());
    i1.mul(i2);
    System.out.println("i1 after multiplication = " + i1.toString());

    try {
      i1.div(i2);
      System.out.println("i1 after division = " + i1.toString());
    } catch (Exception e) {
      System.out.println(e);
    }
		
	}
	
	public void complexTest() {
		
	}

	public static void main(String[] args) {
		Tester t = new Tester();
		t.imaginaryTest();
		// t.complexTest();
	}

}