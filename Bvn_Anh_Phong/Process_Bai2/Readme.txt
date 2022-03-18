                /*********************** PROCESS BÀI 2 ***********************/

    Đề bài: Điều gì xảy ra khi chúng ta sử dụng họ hàm execute (execl/exevp/exepv)? 
Giải thích và viết một chương trình để xác minh câu trả lời. Sau đó hãy cho biết bản chất khi lệnh system() hoạt động như thế nào.


                /*********************** ĐÁP ÁN BÀI 2 ***********************/

    +, Ta có: Hàm exec là một họ các hàm có chức năng thay thế "ảnh"(image?) của tiến trình hiện tại bằng "ảnh"(image?) của tiến trình mới.
Chú ý:   Hàm exec chỉ trả về khi có lỗi xảy ra. Khi hàm exec() thành công, nó sẽ thay thế chương trình cũ bằng chương 
    trình mới(ngay tiến trình hiện tại gọi nó). Vì thế nên các lênh dưới hàm exec sẽ bị thay thế bởi những lệnh khác.
        --> Ta có thể thấy ở chương trình main(), khi có hàm execl(), hàm in "I'm process child" không được in ra.
        --> Và sau khi thực hiện hàm execl(), process con kết thúc và nhảy vào hàm func().

    
    +, Bản chất lệnh System()
        --> Ta cần include<stdlib.h>
            --> Sử dụng:  system(“date”);
                --> In ra thứ ngày tháng hiện tại.
        System() khi được sử dụng sẽ gọi fork() để tạo quy trình con thực thi lệnh shell được chỉ định trong lệnh bằng Execl()
    System () trả về sau khi lệnh đã được hoàn thành. Trong quá trình thực hiện lệnh, SIGCHLD sẽ bị chặn và sigint và sigquit sẽ bị bỏ qua, 
    trong quá trình gọi cho hệ thống (). 
    Nếu lệnh là null, thì System () trả về trạng thái cho biết liệu shell có available để thực thi được trên hệ thống không.