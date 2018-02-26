vector<int> getPrimes(int A) {
    vector<bool> nums(A, true);
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i]) {
            for (int j = i * 2; j < nums.size(); j += i) {
                nums[j] = false;
            }
        }
    }

    vector<int> primes;
    for (int i = 2; i < nums.size(); ++i) {
        if (nums[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> Solution::primesum(int A) {
    vector<int> primes = getPrimes(A);

    int i = 0, j = primes.size() - 1;

    while (i <= j) {
        int summ = primes[i] + primes[j];

        if (summ == A) {
            break;
        } else if (summ > A) {
            j--;
        } else {
            i++;
        }
    }

    vector<int> ans;
    ans.push_back(primes[i]);
    ans.push_back(primes[j]);

    return ans;
}
