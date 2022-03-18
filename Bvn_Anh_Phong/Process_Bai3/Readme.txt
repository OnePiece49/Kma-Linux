                /*********************** PROCESS BÀI 3 ***********************/

    Đề bài: Trình bày cách sử dụng 2 hàm dup()/dup2(). Viết chương trình minh họa cho câu trả lời.



                /*********************** ĐÁP ÁN BÀI 3 ***********************/

    I, Cách sử dụng dup();

Chú ý 1: Trong thư mục chứa các file đang mở, luôn có 3 file đầu tiên là 
    0 = STDIN --> Luồng đầu vào
    1 = STDOUT --> Luồng đầu ra
    2 = STDERR --> Luồng sai dữ liệu

    +,Khi ta gọi hàm dup(), nó sẽ tạo ra một file desciptor mới từ file desciptor(fd) truyền vào
                vd, fd_coppy = dup(fd);
        --> file desciptor mới này(fd_coppy) có thể thay thế cho file desciptor cũ(fd) trong việc đọc ghi file.
            --> Nó cũng mang các cờ trạng thái hay con trỏ giống hết cờ trạng thái và con trỏ của file nó đang hiện hành.
            Vd, Ta lseek(fd, -5, SIGEND) thì bên fd_coppy nóp cũng sẽ di chuyển con trỏ dịch 5 byte so với vị trí cuối cùng
                    --> Nó kiểu tượng tự ánh xạ(mapping).
    
    +, fd_coppy sẽ có giá trị thấp nhất. 
                Vd, 3 file đầu là 0,1,2 đã nêu trong chú ý 1. 
                    Mà fd = 3
                    Nều giá trị = 4 chưa được sử dụng thì fd_coppy sẽ = 4 
    
--> Vậy hàm này sẽ được áp dụng cho điều gì ??
1, Ứng dụng trong việc kiểm soát đầu ra:
    Vd, Ta close(1) --> Đóng file STDOUT
        Khi ta   fd_coppy =  dup(fd); 
            --> Thì một bản sao của fd là fd_coppy sẽ được lưu vào vị trí 1, nghĩa là fd_coppy = 1.
            --> Lúc này khi ta in tín hiệu bằng printf("abcxyz");
                    --> Thì dữ liệu "abcxyz" sẽ được ghi vào trong file --> Vì file desciptor bằng 1 luôn là đầu ra
                            --> Mà dữ liệu printf(); lại là đầu ra nên nó ghi vào trong file

2, Ứng dụng trong việc kết hợp Pipe và child;
    --> Code ở file PipeAnDup.c
    --> Ta có như ở trên, ta đóng đầu đọc ghi của từng PROCESS cho phù hợp, rồi gán 1 đầu của Pipe là đầu vào của PROCESS child(STDOUT).
                            và gán 1 đầu của pipe ở bên PROCESS kia là đầu ra của PROCESS parent(STDIN).

            --> Ta thấy 2 dữ liệu đầu ra và đầu vào thông nhau.
                --> Run code để xem kq.


    II, Cách sử dụng dup2(),
        Tương tự như trên --> Nhưng khác với việc bắt buộc fd_coppy phải là giá trị bé nhất mà chưa được PROCESS sử dụng.
            --> Thì ta có thể chọn giá trị cho fd_coppy qua hàm dup2
                fd_coppy = dup2(fd, Gia_tri_muon_chon);
            Vd, fd_coppy = dup_2(fd, 10);
                    --> Lúc này fd_coppy = 10.