//
// Created by Nikita on 21.03.2021.
//

#include "Sidel.h"

std::vector<std::vector<int>> Sidel::sidelRun(std::vector<std::vector<int>> &a, int n) {
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

    std::vector<std::vector<int>>& t = this->sidelRun(b, n);
    std::vector<std::vector<int>>& x = this->multiply(t, a, n);

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

std::vector<std::vector<int>>
Sidel::multiply(std::vector<std::vector<int>> m1, std::vector<std::vector<int>> m2, int n) {
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
