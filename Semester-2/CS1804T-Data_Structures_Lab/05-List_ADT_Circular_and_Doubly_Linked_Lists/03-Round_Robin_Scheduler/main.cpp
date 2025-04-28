#include <iostream>

class Schedule {
private:
  struct Process {
    int remaining_time;
    Process *next;
    explicit Process(int time) : remaining_time(time), next(nullptr) {}
  };

  Process *head = nullptr;
  Process *tail = nullptr;
  int process_count = 0;
  int time_slice = 0;

  void delete_completed_process() {
    if (head == tail) {
      delete head;
      head = tail = nullptr;
    } else {
      Process *completed = head;
      head = head->next;
      tail->next = head;
      delete completed;
    }
    process_count--;
  }

public:
  ~Schedule() {
    while (head != nullptr) {
      delete_completed_process();
    }
  }

  void configure_time_slice() {
    std::cout << "Enter time slice per process: ";
    std::cin >> time_slice;
  }

  void add_process(int duration) {
    Process *new_process = new Process(duration);

    if (head == nullptr) {
      head = tail = new_process;
      new_process->next = head;
    } else {
      tail->next = new_process;
      tail = new_process;
      tail->next = head;
    }
    process_count++;
  }

  void execute_cycle() {
    if (head == nullptr) {
      std::cout << "No processes to execute!\n";
      return;
    }

    head->remaining_time -= time_slice;
    std::cout << "Executed " << time_slice
              << " ms. Remaining: " << head->remaining_time << " ms\n";

    if (head->remaining_time <= 0) {
      delete_completed_process();
    } else {
      // Move to next process
      tail = head;
      head = head->next;
    }

    std::cout << "Pending processes: " << process_count << "\n";
  }
};

int main() {
  Schedule scheduler;
  scheduler.configure_time_slice();

  while (true) {
    std::cout << "\nRound Robin Scheduler\n"
              << "1. Add Process\n"
              << "2. Execute Cycle\n"
              << "3. Exit\n"
              << "Choice: ";

    int choice;
    std::cin >> choice;

    switch (choice) {
    case 1: {
      int duration;
      std::cout << "Process duration (ms): ";
      std::cin >> duration;
      scheduler.add_process(duration);
      break;
    }
    case 2:
      scheduler.execute_cycle();
      break;
    case 3:
      std::cout << "Exiting...\n";
      return 0;
    default:
      std::cout << "Invalid choice\n";
    }
  }
}
