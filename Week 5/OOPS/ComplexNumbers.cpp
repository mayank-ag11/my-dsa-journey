class ComplexNumbers {
    int real;
    int imaginary;
    
    public:
    ComplexNumbers(int r, int i) {
        real = r;
        imaginary = i;
    }
    
    void plus(ComplexNumbers obj) {
        real += obj.real;
        imaginary += obj.imaginary;
    }
    
    void multiply(ComplexNumbers obj) {
        int r = real;
        int i = imaginary;
        
        real = (r*obj.real) - (i*obj.imaginary);
        imaginary = (r*obj.imaginary) + (i*obj.real);
    }
    
    void print() {
        cout << real << " + i" << imaginary;
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }  
}