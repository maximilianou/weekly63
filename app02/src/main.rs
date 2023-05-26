use actix_web::{web, App, HttpResponse, HttpServer};

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    println!("Running Server: localhost:8080/  ");
    HttpServer::new(|| {
        App::new()
            .service(web::resource("/").to(|| async { "hello, how are you!?" }))
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await

}