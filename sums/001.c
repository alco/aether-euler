#include <assert.h>

// solution #1
int two_streams(int N)
{
    int sum = 0;
    for (int i = 3; i < N; i += 3)
        sum += i;
    for (int i = 5; i < N; i += 5)
        if (i % 3) sum += i;
    return sum;
}

// solution #2
int one_stream(int N)
{
    int sum = 0;
    for (int i = 3; i < N; i++)
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    return sum;
}

// solution #4
// this one is used to check correctness
int formula(int N)
{
}

// solution #5
int three_streams(int N)
{
    int sum = 0;
    for (int i = 3; i < N; i += 3) sum += i;
    for (int i = 5; i < N; i += 5) sum += i;
    for (int i = 15; i < N; i += 15) sum -= i;
    return sum;
}

int main(int argc, const char *argv[])
{
    for (int n = 0; n <= 1000; n++) {
        int a = one_stream(n);
        int b = two_streams(n);
        int c = three_streams(n);
        assert(a == b && b == c);
    }
    return 0;
}
