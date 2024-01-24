
//https://app.codility.com/programmers/lessons/6-sorting/number_of_disc_intersections/
//https://www.youtube.com/watch?v=HV8tzIiidSw
int solution(vector<int>& A) {
    // Implement your solution here
    vector<int> sv(A.size(), 0);
    vector<int> ev(A.size(), 0);

    if (A.size() < 2) return 0;

    for (int i = 0; i < A.size(); ++i) {
        sv[i] = i - A[i];
        ev[i] = i + A[i];
    }

    sort(sv.begin(), sv.end());
    sort(ev.begin(), ev.end());

    int ans = 0;
    int open = 0;
    for (int i = 0, j = 0; i < sv.size() && j < ev.size();) {
        //cout << " " << sv[i];
        if (sv[i] <= ev[j]) {
            open += 1;
            ans += (open - 1);
            ++i;
            continue;
        }
        open -= 1;
        ++j;
    }

    return ans;
}

