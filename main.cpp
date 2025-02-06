#include "matrix.h"
#include "util.h"

int main()
{
    Matrix &matrix = Matrix::getInstance();
    cout << endl;
    cout << "====== START GAME =======" << endl;
    cout << endl;

    cout << endl;
    cout << "====== CHOOSE DIFFICULTY ======" << endl;
    cout << "====== A:easy B:hard ======" << endl;
    cout << endl;
    char diff;
    cin >> diff;
    cout << "====== You Have 3 Times to Doublize Your Matrix ======" << endl;

    matrix.initMatrix();
    matrix.showMatrix();

    char cmd;
    while (true)
    {
        cout << "====== GIVE COMMAND ======" << endl;
        cin >> cmd;
        switch (cmd)
        {
        case 's':
            matrix.down();
            matrix.killbydown();
            if (diff == 'A') {
                matrix.nextOne();
            } else if (diff == 'B'){
                matrix.nextTwo();
            } else {
                matrix.nextOne();
            }
            matrix.addStep();
            matrix.showMatrix();
            break;
        case 'w':
            matrix.up();
            matrix.killbyup();
            if (diff == 'A') {
                matrix.nextOne();
            } else {
                matrix.nextTwo();
            }
            matrix.addStep();
            matrix.showMatrix();
            break;
        case 'a':
            matrix.left();
            matrix.killbyleft();
            if (diff == 'A') {
                matrix.nextOne();
            } else {
                matrix.nextTwo();
            }
            matrix.addStep();
            matrix.showMatrix();
            break;
        case 'd':
            matrix.right();
            matrix.killbyright();
            if (diff == 'A') {
                matrix.nextOne();
            } else {
                matrix.nextTwo();
            }
            matrix.addStep();
            matrix.showMatrix();
            break;
        case 'e':
            if (matrix.doublize() == 0)
            {
                matrix.showMatrix();
            }
            break;
        case 'q':
            cout << "====== END GAME ======" << endl;
            cout << "YOU TOOK " << matrix.getStep() << " STEPS" << endl;
            return 0;
        default:
            cout << "====== INVALID COMMAND ======" << endl;
        }
    }
    return 0;
}