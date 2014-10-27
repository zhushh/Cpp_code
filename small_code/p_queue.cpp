#include <iostream>
#include <queue>

using std::cout;
using std::endl;
using std::cin;
using std::priority_queue;

void do_job();
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        do_job();
    }
    return 0;
}
void do_job() {
    int n, m, temp, count = 0;
    priority_queue<int> jobs;
    int *job, *it;

    cin >> n >> m;
    job = new int[n];  // remember delete
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        jobs.push(temp);
        job[i] = temp;
    }

    // simulate the circulation using pointer
    it = job;
    while (!jobs.empty()) {
        temp = jobs.top();
        jobs.pop();
        while ((*it != temp) || (*it == 0)) {
            if (it == (job + n - 1)) it = job;
            else    ++it;
        }
        *it = 0;
        ++count;
        if (&(job[m]) == it) break;
    }
    cout << count << endl;
    delete []job;  // attention
}

