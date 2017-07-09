/*
 * thrift --gen cpp:templates,pure_enums,moveable_types,no_default_operators segment.thrift
 * thrift --gen cpp segment.thrift
 * thrift --gen php segment.thrift
 */
namespace * Article
namespace * Article

exception InvalidRequest {
    1: string reason
}

struct SegWord {
    1: string word,
    2: double weight
}

service ArticleService {
    list<SegWord> Segment( 1:string sentence, 2:i32 topk ) throws (1:InvalidRequest err),
}

