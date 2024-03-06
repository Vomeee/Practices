#include <iostream>
#include <algorithm> // min 함수를 사용하기 위해 필요

using namespace std;

int main()
{
    
    int n; // 집의 개수
    cin >> n;

    int** color_value = new int* [n];
    for (int i = 0; i < n; i++) {
        color_value[i] = new int[3];
    }

    for (int i = 0; i < n; i++) {
        cin >> color_value[i][0] >> color_value[i][1] >> color_value[i][2];
    }

    int dp[3] = { color_value[0][0], color_value[0][1], color_value[0][2] };

    for (int i = 1; i < n; i++)
    {
        int tempdp[3] = { 0, 0, 0 };

        tempdp[0] = min(dp[1] + color_value[i][0], dp[2] + color_value[i][0]);
        tempdp[1] = min(dp[0] + color_value[i][1], dp[2] + color_value[i][1]);
        tempdp[2] = min(dp[0] + color_value[i][2], dp[1] + color_value[i][2]);

        dp[0] = tempdp[0];
        dp[1] = tempdp[1];
        dp[2] = tempdp[2];
    }

    cout << *min_element(dp, dp + 3) << endl; // dp 배열에서 최소값을 찾아 출력

    // 동적으로 할당한 메모리 해제
    for (int i = 0; i < n; i++)
    {
        delete[] color_value[i];
    }
    delete[] color_value;

    return 0;
}
