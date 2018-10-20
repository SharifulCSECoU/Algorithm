#include<bits/stdc++.h>

using namespace std;

string Text, Pattern;

int F[1000007];

void Failure_Function()
{
    F[0] = 0;

    int K = 1, Len = 0, Len_P = Pattern.size();

    while(K < Len_P)
    {
        if(Pattern[K] == Pattern[Len])
            F[K++] = Len++;

        else
        {
            if(Len != 0)
                Len = F[Len - 1];

            else
                F[K++] = 0;
        }
    }
}

int KMP_Match()
{
    int i = 0, j = 0, Ret = -1;

    int Len_T = Text.size(), Len_P = Pattern.size();

    while(i < Len_T)
    {
        if(Text[i] == Pattern[j])
        {
            i++;
            j++;

            if(j == Len_P)
            {
                Ret = i - Len_P;
                j = F[j - 1];
            }
        }

        else
        {
            if(j != 0)
                j = F[j - 1];

            else
                i++;
        }
    }

    return Ret;
}

int main()
{
    int Test;

    cin >> Test;

    while(Test--)
    {
        cin >> Text >> Pattern;

        Failure_Function();

        int Result = KMP_Match();

        if(Result != -1)
            cout << "YES  " << Result << endl << endl;

        else
            cout << "NO  " << -1 << endl << endl;
    }

    return 0;
}
