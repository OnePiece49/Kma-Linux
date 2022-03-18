                    /*********************** PIPE BÀI 1 ***********************/
    Đề bài:  Viết một chương trình sử dụng hai pipe để cho phép giao tiếp hai chiều giữa hai tiến trình cha và con.
        Parent process lặp lại việc đọc dữ  liệu văn bản từ bàn phím và sử dụng một trong các pipe để gửi văn bản đến child
         process, child process chuyển nó thành chữ hoa và gửi lại cho parent process qua pipe còn lại. Parent process đọc dữ
         liệu trả về từ child process và in ra màn hình trước khi lặp lại quá trình một lần nữa.