#include "stdio.h"
#include "stdlib.h"
#include "math.h"

typedef struct Positions
{
    double x;
    double y;
} Position;

double min(double a, double b) { return a < b ? a : b; }

double dist(Position p1, Position p2)
{
    return sqrt(((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y)));
}

void mergeX(Position arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int i = 0, j = 0, k = 0;
    Position *b = calloc(n1 + n2, sizeof(Position));

    while (i < n1 && j < n2)
    {
        if (arr[left + i].x < arr[mid + 1 + j].x)
        {
            b[k] = arr[left + i];
            i++;
        }
        else
        {
            b[k] = arr[mid + 1 + j];
            j++;
        }
        k++;
    }

    if (i == n1)
    {
        for (int z = j; z < n2; z++)
        {
            b[k] = arr[mid + z + 1];
            k++;
        }
    }
    else
    {
        for (int z = i; z < n1; z++)
        {
            b[k] = arr[left + z];
            k++;
        }
    }

    for (int z = 0; z < (n1 + n2); z++)
    {
        arr[left + z] = b[z];
    }
}

void mergeSortX(Position arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSortX(arr, left, mid);
        mergeSortX(arr, mid + 1, right);

        mergeX(arr, left, mid, right);
    }
}

double BruteForce(Position Space[], int n, double minDis)
{
    double Dis;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = i + 1; j < n; j++)
        {
            Dis = dist(Space[i], Space[j]);
            if (Dis < minDis)
            {
                minDis = Dis;
            }
        }
    }

    return minDis;
}

double mainClosest(Position Space[], int left, int right)
{
    int mid = (left + right) / 2;
    int size = (right - left) + 1;

    if (size < 2)
    {
        return __DBL_MAX__;
    }
    else if (size == 2)
    {
        dist(Space[left], Space[right]);
    }
    else if (size == 3)
    {
        min(dist(Space[left], Space[mid]), min(dist(Space[mid], Space[right]), dist(Space[left], Space[right])));
    }

    double dl, dr, d;
    dl = mainClosest(Space, left, mid);
    dr = mainClosest(Space, mid + 1, right);

    d = min(dl, dr);

    Position strip[size];
    int n = 0;
    for (size_t i = left; i <= right; i++)
    {
        if (Space[i].x >= (Space[mid].x - d) && Space[i].x <= (Space[mid].x + d))
        {
            strip[n] = Space[i];
            n++;
        }
    }

    return BruteForce(strip, n, d);
}

int main()
{
    int n;
    scanf("%d", &n);
    Position Space[n];

    for (size_t i = 0; i < n; i++)
    {
        scanf("%lf %lf", &Space[i].x, &Space[i].y);
    }

    mergeSortX(Space, 0, n - 1);

    double minDis = mainClosest(Space, 0, n - 1);

    printf("%.4f", minDis);
}