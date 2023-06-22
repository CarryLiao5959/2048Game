#include "matrix.h"
#include "util.h"

void Matrix::down(){
    for(int j=0; j<4; j++){
        int base = 3;
        while(base>0){
            // 找到最低的空位
            while(base>0&&m_matrix[base][j]!=0){
                base--;
            }
            if(base<=0){
                break;
            }
            // 找到空位之上最低的数字
            int top = base-1;
            while(top>=0&&m_matrix[top][j]==0){
                top--;
            }
            if(top<0){
                break;
            }else{
                m_matrix[base][j]=m_matrix[top][j];
                m_matrix[top][j]=0;
                base=top-1;
            }
        }
    }
    m_lastop='d';
}

void Matrix::up(){
    for(int j=0; j<4; j++){
        int base = 0;
        while(base<4){
            // 找到最高的空位
            while(base<4&&m_matrix[base][j]!=0){
                base++;
            }
            if(base>=3){
                break;
            }
            // 找到空位之下最高的数字
            int top = base+1;
            while(top<4&&m_matrix[top][j]==0){
                top++;
            }
            if(top>3){
                break;
            }else{
                m_matrix[base][j]=m_matrix[top][j];
                m_matrix[top][j]=0;
                base=top+1;
            }
        }
    }
    m_lastop='u';
}

void Matrix::left(){
    for(int i=0; i<4; i++){
        int base = 0;
        while(base<4){
            // 找到最高的空位
            while(base<4&&m_matrix[i][base]!=0){
                base++;
            }
            if(base>=3){
                break;
            }
            // 找到空位之下最高的数字
            int top = base+1;
            while(top<4&&m_matrix[i][top]==0){
                top++;
            }
            if(top>3){
                break;
            }else{
                m_matrix[i][base]=m_matrix[i][top];
                m_matrix[i][top]=0;
                base=top+1;
            }
        }
    }
    m_lastop='l';
}

void Matrix::right(){
    for(int i=0; i<4; i++){
        int base = 3;
        while(base>0){
            // 找到最高的空位
            while(base>0&&m_matrix[i][base]!=0){
                base--;
            }
            if(base<=0){
                break;
            }
            // 找到空位之下最高的数字
            int top = base-1;
            while(top>=0&&m_matrix[i][top]==0){
                top--;
            }
            if(top<0){
                break;
            }else{
                m_matrix[i][base]=m_matrix[i][top];
                m_matrix[i][top]=0;
                base=top-1;
            }
        }
    }
    m_lastop='r';
}

void Matrix::nextOne(){
    if(getempty()==1){
        cout<<"====== GAME OVER ======"<<endl;
        cout << "=== YOU TOOK ["<< this->getStep()  <<"] STEPS ==="<<endl;
        exit(0);
    }
    int pos=getRand16();
    int row=pos/4;
    int col=pos%4;
    while(m_matrix[row][col]!=0){
        pos=getRand16();
        row=pos/4;
        col=pos%4;
    }
    m_matrix[row][col]=getTowOrFour();
}

void Matrix::kill(){
    if(m_lastop=='d'){
        killbydown();
    }else if(m_lastop=='u'){
        killbyup();
    }else if(m_lastop=='l'){
        killbyleft();
    }else if(m_lastop=='r'){
        killbyright();
    }
}

void Matrix::killbydown(){
    for(int j=0; j<4; j++){
        int base = 3;
        int top = 2;
        if(m_matrix[base][j]==0){
            continue;
        }
        for(int i=0;i<3;i++){
            while(top>=0&&m_matrix[top][j]==0){
                top--;
            }
            while(top>=0&&m_matrix[top][j]==m_matrix[base][j]){
                m_matrix[base][j]*=2;
                m_matrix[top][j]=0;
                while(top>=0&&m_matrix[top][j]==0){
                    top--;
                }
            }
            base=top;
            top=base-1;
        }
    }
    down();
}

void Matrix::killbyup(){
    for(int j=0; j<4; j++){
        int base = 0;
        int top = 1;
        if(m_matrix[base][j]==0){
            continue;
        }
        for(int i=0;i<3;i++){
            while(top<4&&m_matrix[top][j]==0){
                top++;
            }
            while(top<4&&m_matrix[top][j]==m_matrix[base][j]){
                m_matrix[base][j]*=2;
                m_matrix[top][j]=0;
                while(top<4&&m_matrix[top][j]==0){
                    top++;
                }
            }
            base=top;
            top=base+1;
        }
    }
    up();
}

void Matrix::killbyleft(){
    for(int i=0; i<4; i++){
        int base = 0;
        int top = 1;
        if(m_matrix[i][base]==0){
            continue;
        }
        for(int k=0;k<3;k++){
            while(top<4&&m_matrix[i][top]==0){
                top++;
            }
            while(top<4&&m_matrix[i][top]==m_matrix[i][base]){
                m_matrix[i][base]*=2;
                m_matrix[i][top]=0;
                while(top<4&&m_matrix[i][top]==0){
                    top++;
                }
            }
            base=top;
            top=base+1;
        }
    }
    left();
}

void Matrix::killbyright(){
    for(int i=0; i<4; i++){
        int base = 3;
        int top = 2;
        if(m_matrix[i][base]==0){
            continue;
        }
        for(int k=0;k<3;k++){
            while(top>=0&&m_matrix[i][top]==0){
                top--;
            }
            while(top>=0&&m_matrix[i][top]==m_matrix[i][base]){
                m_matrix[i][base]*=2;
                m_matrix[i][top]=0;
                while(top>=0&&m_matrix[i][top]==0){
                    top--;
                }
            }
            base=top;
            top=base-1;
        }
    }
    right();
}