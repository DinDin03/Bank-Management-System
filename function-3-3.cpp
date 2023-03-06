double weighted_average(int array[], int n)
{
    double sum = 0.0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (array[i] == array[j])
            {
                count++;
            }
        }
        sum += (double(array[i] * count) / n);
    }
    return sum;
}