struct suffix_array {
    suffix_array (string str)
      : original_str(str) {
        str += '#';
        int length = str.size();

        for (int i = 0; i < length; i++)
            suffs.push_back(i);
        sort(begin(suffs), end(suffs), [&](int lhs, int rhs){ return str[lhs] < str[rhs]; });
        
        vector<int> cmp_values(length);
        int max_value = 0;
        for (int i = 1; i < length; i++) {
            if (str[suffs[i]] != str[suffs[i - 1]])
                max_value++;
            cmp_values[suffs[i]] = max_value;
        }

        auto get_value_pair = [&](int idx, int shift) -> pair<int, int> {
            return {cmp_values[idx], cmp_values[(idx + shift) % length]};
        };
        for (int cmp_len = 1; cmp_len < length; cmp_len *= 2) {
            vector<int> counter(max_value + 1);
            for (int value: cmp_values)
                counter[value]++;
            for (int i = 1; i <= max_value; i++)
                counter[i] += counter[i - 1];
            vector<int> new_suffs(length);
            for (int i = length - 1; i >= 0; i--) {
                int prev = (suffs[i] - cmp_len + length) % length;
                int prev_value = cmp_values[prev];
                new_suffs[--counter[prev_value]] = prev;
            }
            suffs.swap(new_suffs);
            vector<int> new_values(length);
            max_value = 0;
            for (int i = 1; i < length; i++) {
                pair<int, int> prev_value = get_value_pair(suffs[i - 1], cmp_len);
                pair<int, int> curr_value = get_value_pair(suffs[i], cmp_len);
                if (prev_value != curr_value)
                    max_value++;
                new_values[suffs[i]] = max_value;
            }
            cmp_values.swap(new_values);
        }
        // erase '#' symbol from sorted suffix array
        suffs.erase(suffs.begin());
    }

    string original_str;
    vector<int> suffs;
};
