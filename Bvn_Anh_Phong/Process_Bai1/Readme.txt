                /*********************** PROCESS BÀI 1 ***********************/

    Đề bài: Giả sử rằng một parent process đã thiết lập một handler cho SIGCHLD và cũng block tín hiệu này. Sau đó, một trong 
các child process của nó thoát ra và parent process sau đó thực hiện wait() để thu thập trạng thái của child process.
Điều gì xảy ra khi parent process bỏ chặn SIGCHLD?  Viết một chương trình để xác minh câu trả lời. 


                /*********************** ĐÁP ÁN BÀI 1 ***********************/ 

Ta có: Nếu tiến trình con kết thúc trước tiến trình cha, thì tiến trình con sẽ là tiến trình zombie.
        --> Nhưng khi tiến trình cha kết thúc, thì tiến trình con cũng tự được giải phóng và thoát khỏi trạng thái zombie.

    --> Để chủ động ngăn chặn sinh ra tiến trình zombie, ta sử dụng hàm wait() để thu nhận tín hiệu kết thúc của tiến trình con.
        --> Ta kết hợp với hàm signal() để thực hiện điều này.
            Vd,     void func()
                    {
                        wait(NULL);
                    }
                    signal(SIGCHLD, func);

    --> Chú ý: Hàm signal() sau khi được gọi sẽ không bị block ở đấy, mà tiếp tục chạy các câu lệnh bên dưới
            --> Khi nào tín hiệu con kết thúc, signal() sẽ nhảy vào hàm fun(), thực hiện lệnh wait() và giải phóng hoàn toàn 
                        tiến trình con.
        
--> Vậy khi ta bỏ chận SIGCHLD thì khi tiến trình cha còn hoạt động, mà tiến trình con kết thúc thì sẽ sinh ra tiến trình zombie


Chú ý 1: khi tiến trình cha kết thúc trước tiến trình con   
        --> Process con được gọi là tiến trình mồ côi(ORPHANCE).