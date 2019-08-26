#include <bits/stdc++.h>
#define MAX_N 15
#define OPPO_STATE(S) (((1<<n)-1)^S)    // state of opponent
#define CONTAIN(S,c) ((S&(1<<(c-1)))>0) // if state S contains card c

using namespace std;

int n, m;
double p[MAX_N + 1][MAX_N + 1]; // p[i][j]: probability that i win j
vector<int> q;  // query

// transition probability
// tp[S][i]:
// probability that state S transits to S' by
// get a new card i / lose an owned card i
double tp[1 << MAX_N][MAX_N + 1];

double pM[MAX_N];   // pM[i]: probability that M plays i
double pQ[MAX_N];   // pQ[i]: probability that Q plays i

double matrix[5000][5000];  // coefficient matrix of equation group

void show_matrix(int MAX_S) {
    for (int i = 1; i < MAX_S; ++i) {
        for (int j = 1; j <= MAX_S; ++j)
            printf("%.2lf ", matrix[i][j]);
        putchar('\n');
    }
    putchar('\n');
}

void calc_pX(int state, double* pX) {
    double S[MAX_N];
    double sum_S = 0;
    for (int i = 1; i <= n; ++i) {
        pX[i] = S[i] = 0.0;
    }
    
    int _state = OPPO_STATE(state);
    for (int i = 1; i <= n; ++i) {
        if (!CONTAIN(state,i)) continue;
        for (int j = 1; j <= n; ++j) {
            if (!CONTAIN(_state,j)) continue;
            S[i] += p[i][j];
        }
        sum_S += S[i];
    }
    for (int i = 1; i <= n; ++i) {
        if (!CONTAIN(state,i)) continue;
        pX[i] = S[i] / sum_S;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            scanf("%lf", &p[i][j]);
            p[j][i] = 1.0 - p[i][j];
        }
    }
    for (int i = 1; i <= m; ++i) {
        int S = 0;
        for (int j = 1; j <= n; ++j){
            int k;
            scanf("%d", &k);
            if (k == 1) {
                S += 1 << j-1;
            }
        }
        q.push_back(S);
    }

    int MAX_S = (1 << n) - 1;
    memset(tp , 0 , sizeof(tp));

    // Calculate probability of winning
    // in the case of all possible initial states
    // except state 0 and 2^n-1 (They are final states).
    for (int S = 1; S < MAX_S; ++S) {
        int _S = OPPO_STATE(S);
        calc_pX(S, pM);
        calc_pX(_S, pQ);
        // for (int i = 1; i <= n && CONTAIN(S,i); ++i) {   // FIXME: if in this way, unwork
        for (int i = 1; i <= n; ++i) {
            if (!CONTAIN(S,i)) continue;
            for (int j = 1; j <= n; ++j) {
                if (!CONTAIN(_S,j)) continue;
                double p_win = p[i][j];
                // M win and will get card j form Q
                tp[S][j] += pM[i] * pQ[j] * p_win;
                // M lose and will give card i to Q
                tp[S][i] += pM[i] * pQ[j] * (1 - p_win);
            }
        }
    }

    // Calculate coefficient matrix.
    memset(matrix, 0, sizeof(matrix));
    for (int S = 1; S < MAX_S; ++S) {
        for (int i = 1; i <= n; ++i) {
            int S_next = S ^ (1 << i-1);
            if (S_next == MAX_S) {
                matrix[S][S_next] = -tp[S][i];
            } else {
                matrix[S][S_next] = tp[S][i];
            }
        }
        matrix[S][S] = -1.0;
    }

    // gauss elimination
    int h = 1;
    int k = 1;
    while (h < MAX_S && k <= MAX_S) {
        // Choosing the largest absolute value of the pivot
        // improves the numerical stability of the algorithm,
        // when floating point is used for representing numbers.
        int max_i = k;
        for (int i = k + 1; i < MAX_S; ++i) {
            if ( fabs(matrix[i][k]) > fabs(matrix[max_i][k]) ) {
                max_i = i;
            }
        }
        if (matrix[max_i][k] == 0) {
            ++k;
        } else {
            // swap row h and row max_i
            for (int j = 1; j <= MAX_S; ++j) {
                swap(matrix[h][j], matrix[max_i][j]);
            }
            // elimination
            for (int i = h + 1; i < MAX_S; ++i) {
                double f = matrix[i][k] / matrix[h][k];
                matrix[i][k] = 0;
                for (int j = k + 1; j <= MAX_S; ++j) {
                    matrix[i][j] -= f * matrix[h][j];
                }
            }

            ++h;
            ++k;
        }
        // show_matrix(MAX_S);
    }

    for (int k = MAX_S - 1; k > 0; --k) {
        matrix[k][MAX_S] /= matrix[k][k];
        matrix[k][k] = 1;
        for (int i = k - 1; i > 0; --i) {
            matrix[i][MAX_S] -= matrix[i][k] * matrix[k][MAX_S];
            matrix[i][k] = 0;
        }
        // show_matrix(MAX_S);
    }

    matrix[0][MAX_S] = 0.0;
    matrix[MAX_S][MAX_S] = 1.0;

    for (int i = 0; i < q.size(); ++i) {
        printf("%.5lf\n", matrix[q[i]][MAX_S]);
    }

    return 0;
}
