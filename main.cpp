#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2,int n)
{
    std::vector<std::vector<int>> d(n);
    for (unsigned int i=0;i<n;i++) {
        std::vector<int> myRow;
        for (unsigned int j=0;j<n;j++) {
            int sum=0;
            for (unsigned int k=0;k<n;k++) {
                sum+=m1[i][k]*m2[k][j];
            }
            myRow.push_back(sum);
        }
        d[i] = myRow;
    }
    return d;
}

std::vector<std::vector<int>> sidel(std::vector<std::vector<int>>& a, int n)
{
    bool check = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(i != j && a[i][j] != 1)
            {
                check = false;
            }
        }
    }
    if(check) {
        return a;
    }

    std::vector<std::vector<int>> sq = multiply(a, a, n);
    std::vector<std::vector<int>> b(n);

    for (int i = 0; i < n; ++i) {
        b[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if(i != j && (a[i][j] == 1 || sq[i][j] > 0)) {
                b[i][j] = 1;
            }
            else {
                b[i][j] = 0;
            }
        }
    }

    std::vector<std::vector<int>>& t = sidel(b, n);
    std::vector<std::vector<int>>& x = multiply(t, a, n);

    std::vector<int> sum(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            sum[i] += a[i][j];
        }
    }

    std::vector<std::vector<int>> d(n);

    for (int i = 0; i < n; ++i) {
        d[i].resize(n);
        for (int j = 0; j < n; ++j) {
            if(x[i][j] >= t[i][j] * sum[j]) {
                d[i][j] = 2 * t[i][j];
            }
            else {
                d[i][j] = 2 * t[i][j] - 1;
            }
        }
    }

    return d;
}

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

    std::string str = "../input.txt";
    std::string str2 = "../output.txt";
    std::vector<std::vector<int>> a2 = readfile(str);
    std::vector<std::vector<int>> d = sidel(a2, a2.size());
    writefile(d, d.size(), str2);
    return 0;
}
