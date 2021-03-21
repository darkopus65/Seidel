#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Sidel.h"

std::vector<std::vector<int>> readfile(std::string& file)
{
    std::ifstream myfile(file);
    std::string line;

    int n;
    myfile >> n;
    std::vector<std::vector<int>> a(n);

    if (myfile.is_open()) {
        for (int i = 0; i < n; ++i) {
            a[i].resize(n);
            for (int j = 0; j < n; ++j) {
                myfile >> a[i][j];
            }
        }
    }
    myfile.close();
    return a;
}

void writefile(std::vector<std::vector<int>> a, int n, std::string& file)
{
    std::ofstream myfile(file);
    std::string line;

    if (myfile.is_open()) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                myfile << a[i][j] << ' ';
            }
            myfile << '\n';
        }
    }
    myfile.close();
}



int main() {

//    std::vector<std::vector<int>> m = {{0, 1, 1, 1},
//                                       {1, 0, 1, 0},
//                                       {1, 1, 0, 0},
//                                       {1, 0, 0, 0}};
//
//    std::vector<std::vector<int>> m2 = {{0, 1, 1},
//                                        {1, 0, 0},
//                                        {1, 0, 0}};
////    std::vector<std::vector<int>> mm = multiply(m, m, 4);
//
//    std::vector<std::vector<int>> a = {{0, 1, 0, 1, 0, 0, 0, 0},
//                                       {1, 0, 1, 0, 0, 0, 0, 0},
//                                       {0, 1, 0, 0, 0, 0, 0, 0},
//                                       {1, 0, 0, 0, 1, 0, 0, 1},
//                                       {0, 0, 0, 1, 0, 1, 1, 1},
//                                       {0, 0, 0, 0, 1, 0, 1, 0},
//                                       {0, 0, 0, 0, 1, 1, 0, 1},
//                                       {0, 0, 0, 1, 1, 0, 1, 0}};
    Sidel* s = new Sidel();
    std::string str = "../input.txt";
    std::string str2 = "../output.txt";
    std::vector<std::vector<int>> a2 = readfile(str);
    std::vector<std::vector<int>> d = s->sidelRun(a2, a2.size());
    writefile(d, d.size(), str2);
    return 0;
}
