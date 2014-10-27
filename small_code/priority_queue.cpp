// give you a sequence that all of elements is between 0 and 10.
// the number of element is bigger, the priority of this element is higher.
// each number represent a job that should be done, but the one
// which priority is higher will be done firstly. if the front
// element isn't the highest priority element, then push it to
// the end of this sequence.
// now, give you two number n and m, n is the number of elements
// and m is the position of your job. assume that finishing one
// job need one minute and moving the job don't to the end needn't.
// any time. calculate the sum time will be spent when your job
// is finished.(finished job will be delete in the sequence)

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
    job = new int[n];  // remember delete it
    for (int i = 0; i < n; ++i) {
        cin >> temp;
        jobs.push(temp);
        job[i] = temp;
    }
    it = job;
    while (!jobs.empty()) {
        temp = jobs.top();  // tell which job should be done
        jobs.pop();
        // find the highest priority job should be done
        while ((*it != temp) || (*it == 0)) {
            if (it == (job + n - 1)) it = job;
            else    ++it;
        }
        *it = 0;  // flag one job have been finished
        ++count;
        if (&(job[m]) == it) break;
    }
    cout << count << endl;
    delete []job;  // attention~
}

