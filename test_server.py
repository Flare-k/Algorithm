import socket

with socket.socket() as s:
    s.bind("0.0.0.0", 12345)
    s.listen()  # Open server
    print("server start")


    # Client Request 수락
    conn, addr = s.accept()
    with conn:
        print("Connect by ", addr)
        with True:
            data = conn.recv(1024)
            if data.strip() == 'q' : break

            conn.sendall(data)  # echo
