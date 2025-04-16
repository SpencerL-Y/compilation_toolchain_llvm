; ModuleID = '../../target_project_template/build/test_logged.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.T = type { ptr }

@.str = private unnamed_addr constant [71 x i8] c"[OBJ ALLOC] malloc result: %p, in file: %s, at line: %d, variable: %s\0A\00", align 1, !dbg !0
@.str.1 = private unnamed_addr constant [78 x i8] c"[OBJ FREE] free result: %p freed, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [72 x i8] c"[AFTER FREE] freed ptr: %p, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !12
@.str.3 = private unnamed_addr constant [73 x i8] c"[STORE RESULT] store ptr: %p, in file %s, at line %d, variable name: %s\0A\00", align 1, !dbg !17
@.str.4 = private unnamed_addr constant [71 x i8] c"[STACK PTR VAR CREATED] ptr variable name: %s, in file %s, at line %d\0A\00", align 1, !dbg !22
@0 = private unnamed_addr constant [16 x i8] c"x Function:main\00", align 1
@1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@2 = private unnamed_addr constant [16 x i8] c"y Function:main\00", align 1
@3 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@4 = private unnamed_addr constant [16 x i8] c"z Function:main\00", align 1
@5 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@6 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@7 = private unnamed_addr constant [16 x i8] c"y Function:main\00", align 1
@8 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@9 = private unnamed_addr constant [16 x i8] c"y Function:main\00", align 1
@10 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@11 = private unnamed_addr constant [16 x i8] c"x Function:main\00", align 1
@12 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@13 = private unnamed_addr constant [16 x i8] c"x Function:main\00", align 1
@14 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@15 = private unnamed_addr constant [16 x i8] c"z Function:main\00", align 1
@16 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@17 = private unnamed_addr constant [16 x i8] c"y Function:main\00", align 1
@18 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@19 = private unnamed_addr constant [13 x i8] c"[no varname]\00", align 1
@20 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@21 = private unnamed_addr constant [13 x i8] c"[no varname]\00", align 1
@22 = private unnamed_addr constant [38 x i8] c"ptr Function:clexma_log_malloc_result\00", align 1
@23 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@24 = private unnamed_addr constant [43 x i8] c"filename Function:clexma_log_malloc_result\00", align 1
@25 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@26 = private unnamed_addr constant [42 x i8] c"varname Function:clexma_log_malloc_result\00", align 1
@27 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@28 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@29 = private unnamed_addr constant [38 x i8] c"ptr Function:clexma_log_malloc_result\00", align 1
@30 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@31 = private unnamed_addr constant [43 x i8] c"filename Function:clexma_log_malloc_result\00", align 1
@32 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@33 = private unnamed_addr constant [42 x i8] c"varname Function:clexma_log_malloc_result\00", align 1
@34 = private unnamed_addr constant [43 x i8] c"ptr Function:clexma_log_before_free_result\00", align 1
@35 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@36 = private unnamed_addr constant [48 x i8] c"filename Function:clexma_log_before_free_result\00", align 1
@37 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@38 = private unnamed_addr constant [47 x i8] c"varname Function:clexma_log_before_free_result\00", align 1
@39 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@40 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@41 = private unnamed_addr constant [43 x i8] c"ptr Function:clexma_log_before_free_result\00", align 1
@42 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@43 = private unnamed_addr constant [48 x i8] c"filename Function:clexma_log_before_free_result\00", align 1
@44 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@45 = private unnamed_addr constant [47 x i8] c"varname Function:clexma_log_before_free_result\00", align 1
@46 = private unnamed_addr constant [42 x i8] c"ptr Function:clexma_log_after_free_result\00", align 1
@47 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@48 = private unnamed_addr constant [47 x i8] c"filename Function:clexma_log_after_free_result\00", align 1
@49 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@50 = private unnamed_addr constant [46 x i8] c"varname Function:clexma_log_after_free_result\00", align 1
@51 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@52 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@53 = private unnamed_addr constant [42 x i8] c"ptr Function:clexma_log_after_free_result\00", align 1
@54 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@55 = private unnamed_addr constant [47 x i8] c"filename Function:clexma_log_after_free_result\00", align 1
@56 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@57 = private unnamed_addr constant [46 x i8] c"varname Function:clexma_log_after_free_result\00", align 1
@58 = private unnamed_addr constant [37 x i8] c"ptr Function:clexma_log_store_result\00", align 1
@59 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@60 = private unnamed_addr constant [42 x i8] c"filename Function:clexma_log_store_result\00", align 1
@61 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@62 = private unnamed_addr constant [41 x i8] c"varname Function:clexma_log_store_result\00", align 1
@63 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@64 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@65 = private unnamed_addr constant [37 x i8] c"ptr Function:clexma_log_store_result\00", align 1
@66 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@67 = private unnamed_addr constant [42 x i8] c"filename Function:clexma_log_store_result\00", align 1
@68 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@69 = private unnamed_addr constant [41 x i8] c"varname Function:clexma_log_store_result\00", align 1
@70 = private unnamed_addr constant [43 x i8] c"filename Function:clexma_log_alloca_result\00", align 1
@71 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@72 = private unnamed_addr constant [42 x i8] c"varname Function:clexma_log_alloca_result\00", align 1
@73 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@74 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@75 = private unnamed_addr constant [43 x i8] c"filename Function:clexma_log_alloca_result\00", align 1
@76 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@77 = private unnamed_addr constant [42 x i8] c"varname Function:clexma_log_alloca_result\00", align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !37 {
  %1 = alloca i32, align 4
  %2 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @0, ptr @1, i32 110)
  %3 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @2, ptr @3, i32 110)
  %4 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @4, ptr @5, i32 110)
  store i32 0, ptr %1, align 4
    #dbg_declare(ptr %2, !43, !DIExpression(), !48)
    #dbg_declare(ptr %3, !49, !DIExpression(), !50)
    #dbg_declare(ptr %4, !51, !DIExpression(), !52)
  %5 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !53
  call void @clexma_log_malloc_result(ptr %5, ptr @6, i32 12, ptr @7), !dbg !54
  store ptr %5, ptr %3, align 8, !dbg !54
  call void @clexma_log_store_result(ptr %3, ptr @8, i32 12, ptr @9), !dbg !55
  %6 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !55
  call void @clexma_log_malloc_result(ptr %6, ptr @10, i32 13, ptr @11), !dbg !56
  store ptr %6, ptr %2, align 8, !dbg !56
  call void @clexma_log_store_result(ptr %2, ptr @12, i32 13, ptr @13), !dbg !57
  %7 = load ptr, ptr %2, align 8, !dbg !57
  store ptr %7, ptr %4, align 8, !dbg !58
  call void @clexma_log_store_result(ptr %4, ptr @14, i32 15, ptr @15), !dbg !59
  %8 = load ptr, ptr %2, align 8, !dbg !59
  store ptr %8, ptr %3, align 8, !dbg !60
  call void @clexma_log_store_result(ptr %3, ptr @16, i32 16, ptr @17), !dbg !61
  %9 = load ptr, ptr %2, align 8, !dbg !61
  %10 = load ptr, ptr %3, align 8, !dbg !63
  %11 = getelementptr inbounds %struct.T, ptr %10, i64 1, !dbg !64
  %12 = icmp eq ptr %9, %11, !dbg !65
  br i1 %12, label %13, label %15, !dbg !65

13:                                               ; preds = %0
  %14 = load ptr, ptr %2, align 8, !dbg !66
  call void @clexma_log_before_free_result(ptr %14, ptr @18, i32 20, ptr @19), !dbg !68
  call void @free(ptr noundef %14) #5, !dbg !68
  call void @clexma_log_after_free_result(ptr %14, ptr @20, i32 20, ptr @21), !dbg !69
  br label %15, !dbg !69

15:                                               ; preds = %13, %0
  ret i32 0, !dbg !70
}

; Function Attrs: nounwind allocsize(0)
declare noalias ptr @malloc(i64 noundef) #1

; Function Attrs: nounwind
declare void @free(ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_malloc_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !71 {
  %5 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @22, ptr @23, i32 22)
  %6 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @24, ptr @25, i32 22)
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @26, ptr @27, i32 22)
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !77, !DIExpression(), !78)
  call void @clexma_log_store_result(ptr %5, ptr @28, i32 22, ptr @29)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !79, !DIExpression(), !80)
  call void @clexma_log_store_result(ptr %6, ptr @30, i32 22, ptr @31)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !81, !DIExpression(), !82)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !83, !DIExpression(), !84)
  call void @clexma_log_store_result(ptr %8, ptr @32, i32 22, ptr @33), !dbg !85
  %9 = load ptr, ptr %5, align 8, !dbg !85
  %10 = load ptr, ptr %6, align 8, !dbg !86
  %11 = load i32, ptr %7, align 4, !dbg !87
  %12 = load ptr, ptr %8, align 8, !dbg !88
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !89
  ret void, !dbg !90
}

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_before_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !91 {
  %5 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @34, ptr @35, i32 7)
  %6 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @36, ptr @37, i32 7)
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @38, ptr @39, i32 7)
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !92, !DIExpression(), !93)
  call void @clexma_log_store_result(ptr %5, ptr @40, i32 7, ptr @41)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !94, !DIExpression(), !95)
  call void @clexma_log_store_result(ptr %6, ptr @42, i32 7, ptr @43)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !96, !DIExpression(), !97)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !98, !DIExpression(), !99)
  call void @clexma_log_store_result(ptr %8, ptr @44, i32 7, ptr @45), !dbg !100
  %9 = load ptr, ptr %5, align 8, !dbg !100
  %10 = load ptr, ptr %6, align 8, !dbg !101
  %11 = load i32, ptr %7, align 4, !dbg !102
  %12 = load ptr, ptr %8, align 8, !dbg !103
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !104
  ret void, !dbg !105
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_after_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !106 {
  %5 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @46, ptr @47, i32 11)
  %6 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @48, ptr @49, i32 11)
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @50, ptr @51, i32 11)
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !107, !DIExpression(), !108)
  call void @clexma_log_store_result(ptr %5, ptr @52, i32 11, ptr @53)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !109, !DIExpression(), !110)
  call void @clexma_log_store_result(ptr %6, ptr @54, i32 11, ptr @55)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !111, !DIExpression(), !112)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !113, !DIExpression(), !114)
  call void @clexma_log_store_result(ptr %8, ptr @56, i32 11, ptr @57), !dbg !115
  %9 = load ptr, ptr %5, align 8, !dbg !115
  %10 = load ptr, ptr %6, align 8, !dbg !116
  %11 = load i32, ptr %7, align 4, !dbg !117
  %12 = load ptr, ptr %8, align 8, !dbg !118
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !119
  ret void, !dbg !120
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_store_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !121 {
  %5 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @58, ptr @59, i32 15)
  %6 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @60, ptr @61, i32 15)
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @62, ptr @63, i32 15)
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !122, !DIExpression(), !123)
  call void @clexma_log_store_result(ptr %5, ptr @64, i32 15, ptr @65)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !124, !DIExpression(), !125)
  call void @clexma_log_store_result(ptr %6, ptr @66, i32 15, ptr @67)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !126, !DIExpression(), !127)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !128, !DIExpression(), !129)
  call void @clexma_log_store_result(ptr %8, ptr @68, i32 15, ptr @69), !dbg !130
  %9 = load ptr, ptr %5, align 8, !dbg !130
  %10 = load ptr, ptr %6, align 8, !dbg !131
  %11 = load i32, ptr %7, align 4, !dbg !132
  %12 = load ptr, ptr %8, align 8, !dbg !133
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.3, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !134
  ret void, !dbg !135
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_alloca_result(ptr noundef %0, i32 noundef %1, ptr noundef %2) #0 !dbg !136 {
  %4 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @70, ptr @71, i32 19)
  %5 = alloca i32, align 4
  %6 = alloca ptr, align 8
  call void @clexma_log_alloca_result(ptr @72, ptr @73, i32 19)
  store ptr %0, ptr %4, align 8
    #dbg_declare(ptr %4, !139, !DIExpression(), !140)
  call void @clexma_log_store_result(ptr %4, ptr @74, i32 19, ptr @75)
  store i32 %1, ptr %5, align 4
    #dbg_declare(ptr %5, !141, !DIExpression(), !142)
  store ptr %2, ptr %6, align 8
    #dbg_declare(ptr %6, !143, !DIExpression(), !144)
  call void @clexma_log_store_result(ptr %6, ptr @76, i32 19, ptr @77), !dbg !145
  %7 = load ptr, ptr %6, align 8, !dbg !145
  %8 = load ptr, ptr %4, align 8, !dbg !146
  %9 = load i32, ptr %5, align 4, !dbg !147
  %10 = call i32 (ptr, ...) @printf(ptr noundef @.str.4, ptr noundef %7, ptr noundef %8, i32 noundef %9), !dbg !148
  ret void, !dbg !149
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind allocsize(0) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind allocsize(0) }
attributes #5 = { nounwind }

!llvm.dbg.cu = !{!24, !26}
!llvm.ident = !{!29, !29}
!llvm.module.flags = !{!30, !31, !32, !33, !34, !35, !36}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 6, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "src/clexma_logging.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "f52682f913ad0a032c563c43bafa5e67")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 568, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 71)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 10, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 624, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 78)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 14, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 576, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 72)
!17 = !DIGlobalVariableExpression(var: !18, expr: !DIExpression())
!18 = distinct !DIGlobalVariable(scope: null, file: !2, line: 18, type: !19, isLocal: true, isDefinition: true)
!19 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 584, elements: !20)
!20 = !{!21}
!21 = !DISubrange(count: 73)
!22 = !DIGlobalVariableExpression(var: !23, expr: !DIExpression())
!23 = distinct !DIGlobalVariable(scope: null, file: !2, line: 22, type: !3, isLocal: true, isDefinition: true)
!24 = distinct !DICompileUnit(language: DW_LANG_C11, file: !25, producer: "clang version 21.0.0git", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!25 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "ae6da2a73799eaf7d51cdb565107c233")
!26 = distinct !DICompileUnit(language: DW_LANG_C11, file: !27, producer: "clang version 21.0.0git", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, globals: !28, splitDebugInlining: false, nameTableKind: None)
!27 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/clexma_logging.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "f52682f913ad0a032c563c43bafa5e67")
!28 = !{!0, !7, !12, !17, !22}
!29 = !{!"clang version 21.0.0git"}
!30 = !{i32 7, !"Dwarf Version", i32 5}
!31 = !{i32 2, !"Debug Info Version", i32 3}
!32 = !{i32 1, !"wchar_size", i32 4}
!33 = !{i32 8, !"PIC Level", i32 2}
!34 = !{i32 7, !"PIE Level", i32 2}
!35 = !{i32 7, !"uwtable", i32 2}
!36 = !{i32 7, !"frame-pointer", i32 2}
!37 = distinct !DISubprogram(name: "main", scope: !38, file: !38, line: 5, type: !39, scopeLine: 5, spFlags: DISPFlagDefinition, unit: !24, retainedNodes: !42)
!38 = !DIFile(filename: "src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "ae6da2a73799eaf7d51cdb565107c233")
!39 = !DISubroutineType(types: !40)
!40 = !{!41}
!41 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!42 = !{}
!43 = !DILocalVariable(name: "x", scope: !37, file: !38, line: 9, type: !44)
!44 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !45, size: 64)
!45 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "T", scope: !37, file: !38, line: 6, size: 64, elements: !46)
!46 = !{!47}
!47 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !45, file: !38, line: 7, baseType: !44, size: 64)
!48 = !DILocation(line: 9, column: 15, scope: !37)
!49 = !DILocalVariable(name: "y", scope: !37, file: !38, line: 10, type: !44)
!50 = !DILocation(line: 10, column: 15, scope: !37)
!51 = !DILocalVariable(name: "z", scope: !37, file: !38, line: 11, type: !44)
!52 = !DILocation(line: 11, column: 15, scope: !37)
!53 = !DILocation(line: 12, column: 9, scope: !37)
!54 = !DILocation(line: 12, column: 7, scope: !37)
!55 = !DILocation(line: 13, column: 9, scope: !37)
!56 = !DILocation(line: 13, column: 7, scope: !37)
!57 = !DILocation(line: 15, column: 9, scope: !37)
!58 = !DILocation(line: 15, column: 7, scope: !37)
!59 = !DILocation(line: 16, column: 9, scope: !37)
!60 = !DILocation(line: 16, column: 7, scope: !37)
!61 = !DILocation(line: 18, column: 9, scope: !62)
!62 = distinct !DILexicalBlock(scope: !37, file: !38, line: 18, column: 9)
!63 = !DILocation(line: 18, column: 14, scope: !62)
!64 = !DILocation(line: 18, column: 16, scope: !62)
!65 = !DILocation(line: 18, column: 11, scope: !62)
!66 = !DILocation(line: 20, column: 14, scope: !67)
!67 = distinct !DILexicalBlock(scope: !62, file: !38, line: 19, column: 5)
!68 = !DILocation(line: 20, column: 9, scope: !67)
!69 = !DILocation(line: 21, column: 5, scope: !67)
!70 = !DILocation(line: 22, column: 5, scope: !37)
!71 = distinct !DISubprogram(name: "clexma_log_malloc_result", scope: !2, file: !2, line: 5, type: !72, scopeLine: 5, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !26, retainedNodes: !42)
!72 = !DISubroutineType(types: !73)
!73 = !{null, !74, !75, !41, !75}
!74 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!75 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !76, size: 64)
!76 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !4)
!77 = !DILocalVariable(name: "ptr", arg: 1, scope: !71, file: !2, line: 5, type: !74)
!78 = !DILocation(line: 5, column: 37, scope: !71)
!79 = !DILocalVariable(name: "filename", arg: 2, scope: !71, file: !2, line: 5, type: !75)
!80 = !DILocation(line: 5, column: 54, scope: !71)
!81 = !DILocalVariable(name: "line", arg: 3, scope: !71, file: !2, line: 5, type: !41)
!82 = !DILocation(line: 5, column: 68, scope: !71)
!83 = !DILocalVariable(name: "varname", arg: 4, scope: !71, file: !2, line: 5, type: !75)
!84 = !DILocation(line: 5, column: 86, scope: !71)
!85 = !DILocation(line: 6, column: 87, scope: !71)
!86 = !DILocation(line: 6, column: 92, scope: !71)
!87 = !DILocation(line: 6, column: 102, scope: !71)
!88 = !DILocation(line: 6, column: 108, scope: !71)
!89 = !DILocation(line: 6, column: 5, scope: !71)
!90 = !DILocation(line: 7, column: 1, scope: !71)
!91 = distinct !DISubprogram(name: "clexma_log_before_free_result", scope: !2, file: !2, line: 9, type: !72, scopeLine: 9, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !26, retainedNodes: !42)
!92 = !DILocalVariable(name: "ptr", arg: 1, scope: !91, file: !2, line: 9, type: !74)
!93 = !DILocation(line: 9, column: 42, scope: !91)
!94 = !DILocalVariable(name: "filename", arg: 2, scope: !91, file: !2, line: 9, type: !75)
!95 = !DILocation(line: 9, column: 59, scope: !91)
!96 = !DILocalVariable(name: "line", arg: 3, scope: !91, file: !2, line: 9, type: !41)
!97 = !DILocation(line: 9, column: 73, scope: !91)
!98 = !DILocalVariable(name: "varname", arg: 4, scope: !91, file: !2, line: 9, type: !75)
!99 = !DILocation(line: 9, column: 91, scope: !91)
!100 = !DILocation(line: 10, column: 94, scope: !91)
!101 = !DILocation(line: 10, column: 99, scope: !91)
!102 = !DILocation(line: 10, column: 109, scope: !91)
!103 = !DILocation(line: 10, column: 115, scope: !91)
!104 = !DILocation(line: 10, column: 5, scope: !91)
!105 = !DILocation(line: 11, column: 1, scope: !91)
!106 = distinct !DISubprogram(name: "clexma_log_after_free_result", scope: !2, file: !2, line: 13, type: !72, scopeLine: 13, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !26, retainedNodes: !42)
!107 = !DILocalVariable(name: "ptr", arg: 1, scope: !106, file: !2, line: 13, type: !74)
!108 = !DILocation(line: 13, column: 41, scope: !106)
!109 = !DILocalVariable(name: "filename", arg: 2, scope: !106, file: !2, line: 13, type: !75)
!110 = !DILocation(line: 13, column: 58, scope: !106)
!111 = !DILocalVariable(name: "line", arg: 3, scope: !106, file: !2, line: 13, type: !41)
!112 = !DILocation(line: 13, column: 72, scope: !106)
!113 = !DILocalVariable(name: "varname", arg: 4, scope: !106, file: !2, line: 13, type: !75)
!114 = !DILocation(line: 13, column: 90, scope: !106)
!115 = !DILocation(line: 14, column: 88, scope: !106)
!116 = !DILocation(line: 14, column: 93, scope: !106)
!117 = !DILocation(line: 14, column: 103, scope: !106)
!118 = !DILocation(line: 14, column: 109, scope: !106)
!119 = !DILocation(line: 14, column: 5, scope: !106)
!120 = !DILocation(line: 15, column: 1, scope: !106)
!121 = distinct !DISubprogram(name: "clexma_log_store_result", scope: !2, file: !2, line: 17, type: !72, scopeLine: 17, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !26, retainedNodes: !42)
!122 = !DILocalVariable(name: "ptr", arg: 1, scope: !121, file: !2, line: 17, type: !74)
!123 = !DILocation(line: 17, column: 36, scope: !121)
!124 = !DILocalVariable(name: "filename", arg: 2, scope: !121, file: !2, line: 17, type: !75)
!125 = !DILocation(line: 17, column: 53, scope: !121)
!126 = !DILocalVariable(name: "line", arg: 3, scope: !121, file: !2, line: 17, type: !41)
!127 = !DILocation(line: 17, column: 67, scope: !121)
!128 = !DILocalVariable(name: "varname", arg: 4, scope: !121, file: !2, line: 17, type: !75)
!129 = !DILocation(line: 17, column: 85, scope: !121)
!130 = !DILocation(line: 18, column: 89, scope: !121)
!131 = !DILocation(line: 18, column: 94, scope: !121)
!132 = !DILocation(line: 18, column: 104, scope: !121)
!133 = !DILocation(line: 18, column: 110, scope: !121)
!134 = !DILocation(line: 18, column: 5, scope: !121)
!135 = !DILocation(line: 19, column: 1, scope: !121)
!136 = distinct !DISubprogram(name: "clexma_log_alloca_result", scope: !2, file: !2, line: 21, type: !137, scopeLine: 21, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !26, retainedNodes: !42)
!137 = !DISubroutineType(types: !138)
!138 = !{null, !75, !41, !75}
!139 = !DILocalVariable(name: "filename", arg: 1, scope: !136, file: !2, line: 21, type: !75)
!140 = !DILocation(line: 21, column: 43, scope: !136)
!141 = !DILocalVariable(name: "line", arg: 2, scope: !136, file: !2, line: 21, type: !41)
!142 = !DILocation(line: 21, column: 57, scope: !136)
!143 = !DILocalVariable(name: "varname", arg: 3, scope: !136, file: !2, line: 21, type: !75)
!144 = !DILocation(line: 21, column: 75, scope: !136)
!145 = !DILocation(line: 22, column: 87, scope: !136)
!146 = !DILocation(line: 22, column: 96, scope: !136)
!147 = !DILocation(line: 22, column: 106, scope: !136)
!148 = !DILocation(line: 22, column: 5, scope: !136)
!149 = !DILocation(line: 23, column: 1, scope: !136)
