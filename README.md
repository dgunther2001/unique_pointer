### Limited Implementation of `std::unique_ptr<T>`

##### **Note:** This will only work on MacOS as I have configured it to print out memory usage to illustrate that memory is in fact being handled correctly.  
 
#### The following are implemented: 
- Default constructor => `unique_pointer<int> my_ptr(new int(37));`  
- `std::move()` => `unique_pointer<int> my_ptr_2 = std::move(my_ptr);`  
- `->` operator => `my_ptr->some_method();`  
- `*` operator => `*my_ptr;`  
- Get operator => `my_ptr.get();`  
- Destructor => All unique_pointer objects exist on the stack, so this just deallocates any heap memory when the object goes out of scope.
- In addition, we manually delete the `=` and the default copy constructor.  

#### Check your memory:
- When you run this on MacOS, it makes use of the Darwin Mach API to allow the user to print out memory use information about the current process as it runs.  

