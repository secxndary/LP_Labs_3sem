extern "C"
{
	int  getmin(int x[], int y)
	{
		int min = x[0];
		for (int i = 0; i < y; ++i)if (x[i] < min)min = x[i];
		return min;
	}

	int  getmax(int x[], int y)
	{
		int max = x[0];
		for (int i = 0; i < y; ++i)if (x[i] > max)max = x[i];
		return max;
	}
};