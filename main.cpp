#include "matrix.h"
#include "util.h"

int main(){
    Matrix& matrix = Matrix::getInstance();
    cout<<"====== START GAME ======="<<endl;
    matrix.initMatrix();
    matrix.showMatrix();

    char cmd;
    while(true) {
        cout << "====== GIVE COMMAND ======" << endl;
        cin >> cmd;
        switch(cmd) {
            case 'd':
                matrix.down();
                matrix.killbydown();
                matrix.nextOne();
                matrix.showMatrix();
                matrix.addStep();
                break;
            case 'u':
                matrix.up();
                matrix.killbyup();
                matrix.nextOne();
                matrix.showMatrix();
                matrix.addStep();
                break;
            case 'l':
                matrix.left();
                matrix.killbyleft();
                matrix.nextOne();
                matrix.showMatrix();
                matrix.addStep();
                break;
            case 'r':
                matrix.right();
                matrix.killbyright();
                matrix.nextOne();
                matrix.showMatrix();
                matrix.addStep();
                break;
            case 'q':
                cout << "====== END GAME ======" << endl;
                cout << "YOU TOOK "<<matrix.getStep()  <<" STEPS"<<endl;
                return 0;
            default:
                cout << "====== INVALID COMMAND ======" << endl;
        }
    }
    return 0;
}