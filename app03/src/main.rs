use actix_web::{get, post, web, App, HttpResponse, HttpServer, Responder, HttpRequest};

#[get("/")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().body("Hello, now hardcoded!")
}

#[post("/echo")]
async fn echo(req_body: String) -> impl Responder {
    HttpResponse::Ok().body(req_body)
}

async fn manual_hello(req: HttpRequest) -> impl Responder {
    for header in req.headers().into_iter() {
        println!("{:?} = {:?}", header.0, header.1);
    }    
    HttpResponse::Ok().body("Hey! How are you!!?")
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    println!("Running Server: localhost:8080/  ");    
    HttpServer::new(|| {
        App::new()
            .service(hello)
            .service(echo)
            .route("/mosliv", web::get().to(manual_hello))
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}