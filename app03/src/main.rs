use actix_web::{web::{Bytes}, web, get, post, App, HttpResponse, HttpServer, Responder, HttpRequest};
use chrono::{Utc};

#[get("/")]
async fn hello() -> impl Responder {
    HttpResponse::Ok().body("Hello, now hardcoded!")
}

#[post("/echo")]
async fn echo(req_body: String) -> impl Responder {
    HttpResponse::Ok().body(req_body)
}

async fn manual_hello(req: HttpRequest, request_body: Bytes 
) -> impl Responder {
    println!("\n-------------Request Header:\n[{:?}]", Utc::now());

    println!("{:?}", req.head().uri);
    println!("{:?}", req.head().method);
    println!("{:?}", req.head().version);
    println!("{:?}", req.head().peer_addr);
    println!("{:?}", req.app_config().host());
    println!("{:?}", req.app_config().secure());

    for header in req.headers().into_iter() {
        println!("{:?} = {:?}", header.0, header.1);
    }    

    println!("-------------Request Body:");
    println!("{:?}", String::from_utf8( request_body.to_vec() ) );
    println!("-------------");


    HttpResponse::Ok().body("Hey! How are you!!?")
}

#[actix_web::main]
async fn main() -> std::io::Result<()> {
    println!("Running Server: localhost:8080/mosliv/  ");    
    HttpServer::new(|| {
        App::new()
            .service(hello)
            .service(echo)
            .route("/mosliv/", web::get().to(manual_hello))
            .route("/mosliv/", web::post().to(manual_hello))
    })
    .bind(("127.0.0.1", 8080))?
    .run()
    .await
}