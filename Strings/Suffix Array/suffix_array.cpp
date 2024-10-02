struct suffixArray {
    suffixArray (string str)
      : originalStr(str) {
        str += '#';
        int length = str.size();

        for (int i = 0; i < length; i++)
            suffs.push_back(i);
        sort(begin(suffs), end(suffs), [&](int lhs, int rhs){ return str[lhs] < str[rhs]; });
        
        vector<int> cmpValues(length);
        int maxValue = 0;
        for (int i = 1; i < length; i++) {
            if (str[suffs[i]] != str[suffs[i - 1]])
                maxValue++;
            cmpValues[suffs[i]] = maxValue;
        }

        auto getValuePair = [&](int idx, int shift) -> pair<int, int> {
            return {cmpValues[idx], cmpValues[(idx + shift) % length]};
        };
        for (int cmp_len = 1; cmp_len < length; cmp_len *= 2) {
            vector<int> counter(maxValue + 1);
            for (int value: cmpValues)
                counter[value]++;
            for (int i = 1; i <= maxValue; i++)
                counter[i] += counter[i - 1];
            vector<int> newSuffs(length);
            for (int i = length - 1; i >= 0; i--) {
                int prev = (suffs[i] - cmp_len + length) % length;
                int prevValue = cmpValues[prev];
                newSuffs[--counter[prevValue]] = prev;
            }
            suffs.swap(newSuffs);
            vector<int> newValues(length);
            maxValue = 0;
            for (int i = 1; i < length; i++) {
                if (getValuePair(suffs[i - 1], cmp_len) != getValuePair(suffs[i], cmp_len))
                    maxValue++;
                newValues[suffs[i]] = maxValue;
            }
            cmpValues.swap(newValues);
        }
        // erase '#' symbol from suffs
        suffs.erase(suffs.begin());
    }

    string originalStr;
    vector<int> suffs;
};
