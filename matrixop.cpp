#include "matrix.h"
#include "util.h"

void Matrix::down()
{
    for (int j = 0; j < 4; j++)
    {
        int base = 3;
        while (base > 0)
        {
            // 找到最低的空位
            while (base > 0 && m_matrix[base][j] != 0)
            {
                base--;
            }
            if (base <= 0)
            {
                break;
            }
            // 找到空位之上最低的数字
            int top = base - 1;
            while (top >= 0 && m_matrix[top][j] == 0)
            {
                top--;
            }
            if (top < 0)
            {
                break;
            }
            else
            {
                m_matrix[base][j] = m_matrix[top][j];
                m_matrix[top][j] = 0;
                base = top - 1;
            }
        }
    }
    m_lastop = 'd';
}

void Matrix::up()
{
    for (int j = 0; j < 4; j++)
    {
        int base = 0;
        while (base < 4)
        {
            // 找到最高的空位
            while (base < 4 && m_matrix[base][j] != 0)
            {
                base++;
            }
            if (base >= 3)
            {
                break;
            }
            // 找到空位之下最高的数字
            int top = base + 1;
            while (top < 4 && m_matrix[top][j] == 0)
            {
                top++;
            }
            if (top > 3)
            {
                break;
            }
            else
            {
                m_matrix[base][j] = m_matrix[top][j];
                m_matrix[top][j] = 0;
                base = top + 1;
            }
        }
    }
    m_lastop = 'u';
}

void Matrix::left()
{
    for (int i = 0; i < 4; i++)
    {
        int base = 0;
        while (base < 4)
        {
            // 找到最高的空位
            while (base < 4 && m_matrix[i][base] != 0)
            {
                base++;
            }
            if (base >= 3)
            {
                break;
            }
            // 找到空位之下最高的数字
            int top = base + 1;
            while (top < 4 && m_matrix[i][top] == 0)
            {
                top++;
            }
            if (top > 3)
            {
                break;
            }
            else
            {
                m_matrix[i][base] = m_matrix[i][top];
                m_matrix[i][top] = 0;
                base = top + 1;
            }
        }
    }
    m_lastop = 'l';
}

void Matrix::right()
{
    for (int i = 0; i < 4; i++)
    {
        int base = 3;
        while (base > 0)
        {
            // 找到最高的空位
            while (base > 0 && m_matrix[i][base] != 0)
            {
                base--;
            }
            if (base <= 0)
            {
                break;
            }
            // 找到空位之下最高的数字
            int top = base - 1;
            while (top >= 0 && m_matrix[i][top] == 0)
            {
                top--;
            }
            if (top < 0)
            {
                break;
            }
            else
            {
                m_matrix[i][base] = m_matrix[i][top];
                m_matrix[i][top] = 0;
                base = top - 1;
            }
        }
    }
    m_lastop = 'r';
}

void Matrix::nextOne()
{
    if (getempty() == 0 && !can_go_on()) {
        game_over();
    }
    int pos = getRand16();
    int row = pos / 4;
    int col = pos % 4;
    if (!getempty() == 0) {
        while (m_matrix[row][col] != 0)
        {
            pos = getRand16();
            row = pos / 4;
            col = pos % 4;
        }
        m_matrix[row][col] = getTowOrFour();
        cout << "====== YOU TOOK " << m_step << " STEPS ======" << endl;
    } else {
        cout << "====== WRONG INSTRUCTION! ======" << endl;
    }
}

void Matrix::nextTwo()
{
    nextOne();
    if (getempty() == 0) {
        cout << "====== You Need 2 Spaces But Only 1 Left ======" << endl;
        game_over();
    }
    nextOne();
}

void Matrix::kill()
{
    if (m_lastop == 'd')
    {
        killbydown();
    }
    else if (m_lastop == 'u')
    {
        killbyup();
    }
    else if (m_lastop == 'l')
    {
        killbyleft();
    }
    else if (m_lastop == 'r')
    {
        killbyright();
    }
}

void Matrix::killbydown()
{
    for (int j = 0; j < 4; j++)
    {
        int base = 3;
        int top = 2;
        if (m_matrix[base][j] == 0)
        {
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            while (top >= 0 && m_matrix[top][j] == 0)
            {
                top--;
            }
            while (top >= 0 && m_matrix[top][j] == m_matrix[base][j])
            {
                m_matrix[base][j] *= 2;
                m_matrix[top][j] = 0;
                while (top >= 0 && m_matrix[top][j] == 0)
                {
                    top--;
                }
            }
            base = top;
            top = base - 1;
        }
    }
    down();
}

void Matrix::killbyup()
{
    for (int j = 0; j < 4; j++)
    {
        int base = 0;
        int top = 1;
        if (m_matrix[base][j] == 0)
        {
            continue;
        }
        for (int i = 0; i < 3; i++)
        {
            while (top < 4 && m_matrix[top][j] == 0)
            {
                top++;
            }
            while (top < 4 && m_matrix[top][j] == m_matrix[base][j])
            {
                m_matrix[base][j] *= 2;
                m_matrix[top][j] = 0;
                while (top < 4 && m_matrix[top][j] == 0)
                {
                    top++;
                }
            }
            base = top;
            top = base + 1;
        }
    }
    up();
}

void Matrix::killbyleft()
{
    for (int i = 0; i < 4; i++)
    {
        int base = 0;
        int top = 1;
        if (m_matrix[i][base] == 0)
        {
            continue;
        }
        for (int k = 0; k < 3; k++)
        {
            while (top < 4 && m_matrix[i][top] == 0)
            {
                top++;
            }
            while (top < 4 && m_matrix[i][top] == m_matrix[i][base])
            {
                m_matrix[i][base] *= 2;
                m_matrix[i][top] = 0;
                while (top < 4 && m_matrix[i][top] == 0)
                {
                    top++;
                }
            }
            base = top;
            top = base + 1;
        }
    }
    left();
}

void Matrix::killbyright()
{
    for (int i = 0; i < 4; i++)
    {
        int base = 3;
        int top = 2;
        if (m_matrix[i][base] == 0)
        {
            continue;
        }
        for (int k = 0; k < 3; k++)
        {
            while (top >= 0 && m_matrix[i][top] == 0)
            {
                top--;
            }
            while (top >= 0 && m_matrix[i][top] == m_matrix[i][base])
            {
                m_matrix[i][base] *= 2;
                m_matrix[i][top] = 0;
                while (top >= 0 && m_matrix[i][top] == 0)
                {
                    top--;
                }
            }
            base = top;
            top = base - 1;
        }
    }
    right();
}

int Matrix::doublize()
{
    m_double_trys--;
    if(m_double_trys < 0) {
        cout << "====== NO DOUBLE TRYS LEFT ======" << endl;
        return 1;
    }
    for (int i = 0; i < ROW_NUM; i++)
    {
        for (int j = 0; j < ROW_NUM; j++)
        {
            m_matrix[i][j] *= 2;
        }
    }
    return 0;
}

int Matrix::write_file(std::string s) {
    std::ofstream outFile;
    outFile.open("record.txt");
    if (outFile.is_open()) {
        outFile << s << std::endl;
        outFile.close();
    }
    return 0;
}

int Matrix::read_record() {
    std::ifstream inFile;
    inFile.open("record.txt");
    if (inFile.is_open()) {
        std::getline(inFile, m_record);
        inFile.close();
    }
    return 0;
}

void Matrix::write_record() {
    read_record();
    if(m_record == "") {
        m_record = "0";
    }
    if (stoi(m_record) < m_step) {
        cout << "====== YOU BREAK THE RECORD! ======" << endl;
        write_file(to_string(m_step));
    }
}

bool Matrix::can_go_on() {
    for (int i = 0; i < ROW_NUM; i++)
    {
        for (int j = 0; j < ROW_NUM; j++)
        {
            if((j + 1 < ROW_NUM && m_matrix[i][j] == m_matrix[i][j + 1]) || 
               (i + 1 < ROW_NUM && m_matrix[i][j] == m_matrix[i + 1][j])) {
                return true;
               }
        }
    }
    return false;
}

void Matrix::game_over() {
    cout << endl;
    cout << "====== GAME OVER ======" << endl;
    cout << endl;
    cout << "====== YOU TOTALLY TOOK [" << this->getStep() << "] STEPS ======" << endl;
    read_record();
    cout << "====== THE RECENT RECORD IS "<< m_record << " ======" << endl;
    write_record();
    exit(0);
}