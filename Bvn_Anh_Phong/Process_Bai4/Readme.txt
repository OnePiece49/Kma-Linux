                /*********************** PROCESS BÀI 4 ***********************/

Đề bài: Debug là một công việc quan trọng trong việc lập trình do đó hãy tìm hiểu về segmentation fault,
    core dumped và cho biết chúng là gì? Viết một chương trình tái hiện lại lỗi này. Sau khi tái hiện được lỗi, 
    tìm hiểu về gdb và trình bày các bước fix cho lỗi này.


                /*********************** ĐÁP ÁN BÀI 4 ***********************/
1, segmentation fault(core dumped)
    +, Lỗi này xảy ra do những nguyên nhân: 
        +, write vào một vùng nhớ chỉ đọc
        +, Truy cập vào một giá trị của mảng mà ko thuộc mảng :)
            vd: int a[10];
                a[11] = 5; --> Lỗi nhưng ko phải lỗi segmentation
        +, Sử dụng giá trị một biến như là một địa chỉ:
            vd: int a =5
                scanf("%d", n); --> Lỗi nhưng ko phải lỗi segmentation
        +, buffer overflow
            vd: char s[3];
                strcpy(s, "hello"); --> Lỗi nhưng ko phải lỗi segmentation
        +, Gán giá trị cho một con trỏ NULL;
            vd: int *ptr = NULL;
                    *ptr = 1; --> lỗi
        +, Gán giá trị cho một con trỏ khi chưa cho nó trỏ tới địa chỉ nào:
            vd: int *ptr;
                    *ptr = 1; --> lỗi

2, Tìm hiểu gdb:
    -Sử dụng gcc để biên dịch chương trình thành file thực thi, chú ý ta phải thêm option [-g] để cho phép chạy debug.
Lệnh compile như sau: gcc -o -g main main.c
    - Để bắt đầu debug file thự thi -> ta gõ lệnh: gdb [ten_file_thuc_thi]
            Vd: gdb main
    Chú ý 1: trong console của GDB, để thực thi các lệnh của linux
            (gdb) shell [lenh_linux]
        Vd: (gdb) shell ls
    
    -Để set break point ở một vị trí nào đó:
            (gdb) break [so_dong] --> vd: break 5; đặt break point ở dòng thứ 5
            hoặc
            (gdb) break [ten_ham] --> vd: func(); đặt break point ở func()
    -Để xóa break point dùng delete
            (gdb) delete [so_thu_tu_break_point] --> vd delete 2; xóa break point ở vị trí thứ 2

--> sau khi đã đặt breakpoint( hoặc ko cần đặt breakpoint tùy cách chúng ta debug), 
        thì chúng ta bắt đầu chạy chương trình bằng lệnh: (gdb) run

    - Muốn xem chương trình đã dừng ở đâu: (gdb) list
    - Muốn chương trình chạy dòng lệnh kế tiếp thì trong gdb gõ: (gdb) next[so_dong]; --> vd: (gdb) next 3; --> Nhay xuống 3 dòng.
        --> Nếu ko có so_dong thì lệnh tiếp theo sẽ được thực hiện
    
    - Muốn chạy vào bên trong thân hàm : (gdb) step
            Vd: int func(int a) {
                    return a++;
                }
                int main()
                {
                    int a = 5;
                    int arr[10] = {1, 3, 5, 9};
                    for(int i = 0; i < 5; i++) {
                        arr[i] = func(i);
                    }
                }
        --> Thì khi chạy đến dòng arr[i] = func(i);
            --> Nếu ta nhấn next sẽ nhảy tiếp đến lệnh tiếp theo là for(int i = 0; i < 5; i++);
            --> Còn nhấn step sẽ nhảy vào hàm func();
    - Muốn quay lại đầu hàm( chỗ mà bắt đầu mà ta step) thì dùng lệnh: (gdb) return
    - Muốn chương trình thực thi tiếp cho đến breakpoint kế hoặc đếnt hết chương trình: (gdb) continue
            --> Chú ý trong vòng lặp breakpoint kế cũng có thể là chính nó.

    - trong quá trình chạy debug chúng ta muốn xem một biến có giá trị bằng bao nhiêu : (gdb) display [ten_bien]
            --> Vd code ở ngay trên:
                    --> Hiển thị giá trị biến i: display i
                    --> Hiển thị giá trị cả mảng: display arr
                    --> Hiển thị giá trị phần tử thứ 3 trong mảng: display arr[2]
            --> Nó sẽ hiển thị xuyên suốt chương trình
    
    - Muốn in giá trị của 1 biến trong console: (gdb) print [ten_bien]
    - Muốn in địa chỉ của biến (gdb) print &[ten_bien] 
            Vd; print &i
        --> Nó sẽ chỉ hiển thị 1 lần
    
    - Hiển thị kiểu dữ liệu của biến: (gdb) ptype [ten_bien]

    +, Gán giá trị cho 1 biến: set variable [ten_bien] = [value]
                            --> Sau đó chạy lệnh: continue


--> Đặt breakpoint gần chỗ ta nghi nhất, cứ next đến bao giờ phát hiện lỗi.

            