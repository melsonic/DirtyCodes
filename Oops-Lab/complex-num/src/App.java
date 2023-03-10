public class App{

    public static void main(String[] args) {
        Complex a = new Complex(2, 5);
        Complex b = new Complex(4, 7);
        System.out.println("a : " + a.toString() + "\n");
        System.out.println("b : " + b.toString() + "\n");
        System.out.println("\nAddition : \n" + addition(a, b).toString());
        System.out.println("\nSubtraction : \n" + subtraction(a, b).toString());
        System.out.println("\nMultiplication : \n" + multiply(a, b).toString());
        try {
            System.out.println("\nDivision : \n" + division(a, b).toString());
        } catch (Exception e) {
            System.out.println(e.toString());
        }
    }
}
