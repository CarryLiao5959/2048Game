#ifndef MATRIX_H
#define MATRIX_H

#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <random>
#include <unordered_map>
#include <fstream>

#include "util.h"
using namespace std;

class Matrix
{
public:
    Matrix(const Matrix &) = delete;
    Matrix &operator=(const Matrix &) = delete;

    static Matrix &getInstance()
    {
        static Matrix instance;
        return instance;
    }

    void initMatrix()
    {
        init();
    }

    void printMatrix()
    {
        show();
    }

    void showMatrix()
    {
        cout << endl;
        cout << "+----+----+----+----+" << endl;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (m_matrix[i][j] == 0)
                {
                    printf("| \033[30m%3d\033[0m", m_matrix[i][j]); // black
                }
                else if (m_matrix[i][j] == 2)
                {
                    printf("| \033[37m%3d\033[0m", m_matrix[i][j]); // white
                }
                else if (m_matrix[i][j] == 4)
                {
                    printf("| \033[33m%3d\033[0m", m_matrix[i][j]); // yellow
                }
                else if (m_matrix[i][j] == 8)
                {
                    printf("| \033[31m%3d\033[0m", m_matrix[i][j]); // red
                }
                else if (m_matrix[i][j] == 16)
                {
                    printf("| \033[32m%3d\033[0m", m_matrix[i][j]); // green
                }
                else if (m_matrix[i][j] == 32)
                {
                    printf("| \033[34m%3d\033[0m", m_matrix[i][j]); // blue
                }
                else if (m_matrix[i][j] == 64)
                {
                    printf("| \033[35m%3d\033[0m", m_matrix[i][j]); // magenta
                }
                else if (m_matrix[i][j] == 128)
                {
                    printf("| \033[36m%3d\033[0m", m_matrix[i][j]); // cyan
                }
                else if (m_matrix[i][j] == 256)
                {
                    printf("| \033[97m%3d\033[0m", m_matrix[i][j]); // light white
                }
                else if (m_matrix[i][j] == 512)
                {
                    printf("| \033[95m%3d\033[0m", m_matrix[i][j]); // light yellow
                }
                else if (m_matrix[i][j] == 1024)
                {
                    printf("| \033[94m%3d\033[0m", m_matrix[i][j]); // light green
                }
                else if (m_matrix[i][j] == 2048)
                {
                    printf("| \033[93m%3d\033[0m", m_matrix[i][j]); // light blue
                }
                else
                {
                    printf("| \033[91m%3d\033[0m", m_matrix[i][j]); // light red
                }
            }
            cout << "|" << endl;
            cout << "+----+----+----+----+" << endl;
        }
        cout << endl;
    }

    void init()
    {
        int random_number = getRand16();
        int row = random_number / 4;
        int col = random_number % 4;
        m_matrix[row][col] = getTowOrFour();
    }

    void show()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cout << m_matrix[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    void addStep()
    {
        m_step++;
    }

    int getStep()
    {
        return m_step;
    }

    void down();
    void up();
    void left();
    void right();
    void nextOne();
    void nextTwo();
    void kill();
    void killbydown();
    void killbyup();
    void killbyleft();
    void killbyright();
    int doublize();
    int write_file(std::string s);
    void write_record();
    int read_record();
    bool can_go_on();
    void game_over();
    int getempty()
    {
        int n = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (m_matrix[i][j] == 0)
                {
                    n++;
                }
            }
        }
        return n;
    }


private:
    int m_step;
    char m_lastop;
    int m_double_trys = DOUBLE_TRYS;
    std::string m_record;
    vector<vector<int>> m_matrix;
    Matrix() : m_step(0), m_matrix(4, vector<int>(4, 0)) {}
    ~Matrix() {}
};

#endif