#include <iostream>
#include "unique_pointer.cpp"

#ifdef __APPLE__
    #include <mach/mach.h>
#else
    #error "OS Not Supported -- ABORTING\n"
#endif


void printMemoryUsage(const std::string& tag) {

    mach_task_basic_info info;
    mach_msg_type_number_t infoCount = MACH_TASK_BASIC_INFO_COUNT;
    task_t task = mach_task_self();

    if (task_info(task, MACH_TASK_BASIC_INFO, (task_info_t)&info, &infoCount) != KERN_SUCCESS) {
        std::cerr << "Task infor not retrieved correctly.\n";
        return;
    }

    std::cout << tag << "Memory Usage: " << info.resident_size / 1024 << " KB\n";
}

int main() {
    printMemoryUsage("Start of main() -- ");
    unique_pointer<int> my_ptr(new int(33));
    printMemoryUsage("Allocation of ptr1 complete -- ");
    //std::cout << *my_ptr << "\n";
    unique_pointer<int> my_ptr_2 = std::move(my_ptr);
    printMemoryUsage("Movement of ptr1 and allocation of ptr2 complete. -- ");
    //std::cout << *my_ptr_2 << "\n";
    if (my_ptr.get() == nullptr) {
        std::cout << "Initial pointer is now a null pointer after move.\n";
    } else {
        std::cout << "Initial pointer not reset after move - BUG.\n";
    }

    return 0;
}