package Lecture.OOPS;

public class Polynomial {
    private int degCoeff[];
	
    public Polynomial() {
        degCoeff = new int[10];
    }

    public Polynomial(int capacity) {
        degCoeff = new int[capacity];
    }

	/* This function sets coefficient for a particular degree value, if degree is not there in the polynomial
	 *  then corresponding term(with specified degree and value is added int the polynomial. If the degree
	 *  is already present in the polynomial then previous coefficient is replaced by
	 *  new coefficient value passed as function argument
	*/
	public void setCoefficient(int deg, int coef){
        if(deg >= degCoeff.length) {
            int newDegCoeff[] = new int[deg+1];
            for(int i = 0; i < degCoeff.length; i++)
                newDegCoeff[i] = degCoeff[i];

            degCoeff = newDegCoeff;
        }

        degCoeff[deg] = coef;
	}
	
	// Prints all the terms(only terms with non zero coefficients are to be printed) in increasing order of degree. 
	public void print(){
		for(int i = 0; i < degCoeff.length; i++) {
            if(degCoeff[i] != 0)
                System.out.print(degCoeff[i] + "x" + i + " ");
        }
        System.out.println();
	}

	
	// Adds two polynomials and returns a new polynomial which has result
	public Polynomial add(Polynomial p){
        int newcap = Math.max(degCoeff.length, p.degCoeff.length);

        Polynomial newP = new Polynomial(newcap);
        int i = 0, l = Math.min(degCoeff.length, p.degCoeff.length);

        while(i < l) {
            newP.degCoeff[i] = degCoeff[i] + p.degCoeff[i];
            i++;
        }
        while(i < degCoeff.length) {
            newP.degCoeff[i] = degCoeff[i];
            i++;
        }

        while(i < p.degCoeff.length) {
            newP.degCoeff[i] = p.degCoeff[i];
            i++;
        }

		return newP;
	}
	
	// Subtracts two polynomials and returns a new polynomial which has result
	public Polynomial subtract(Polynomial p){
        int newcap = Math.max(degCoeff.length, p.degCoeff.length);

        Polynomial newP = new Polynomial(newcap);
        int i = 0, l = Math.min(degCoeff.length, p.degCoeff.length);

        while(i < l) {
            newP.degCoeff[i] = degCoeff[i] - p.degCoeff[i];
            i++;
        }
        while(i < degCoeff.length) {
            newP.degCoeff[i] = degCoeff[i];
            i++;
        }

        while(i < p.degCoeff.length) {
            newP.degCoeff[i] = -p.degCoeff[i];
            i++;
        }

		return newP;
	}
	
	// Multiply two polynomials and returns a new polynomial which has result
	public Polynomial multiply(Polynomial p){
		int newcap = degCoeff.length + p.degCoeff.length;
        Polynomial newP = new Polynomial(newcap);

        for(int i = 0; i < degCoeff.length; i++) {
            for(int j = 0; j < p.degCoeff.length; j++) {
                newP.degCoeff[i + j] += (degCoeff[i] * p.degCoeff[j]);
            }
        }

        return newP;
	}
}