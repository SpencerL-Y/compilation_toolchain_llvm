; ModuleID = '../../target_project_template/build/test.c.ll'
source_filename = "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.T = type { ptr }

@.str = private unnamed_addr constant [72 x i8] c"[OBJ CERATE] malloc result: %p, in file: %s, at line: %d, variable: %s\0A\00", align 1, !dbg !0
@0 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1
@2 = private unnamed_addr constant [11 x i8] c"src/test.c\00", align 1
@3 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !18 {
  %1 = alloca i32, align 4
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  store i32 0, ptr %1, align 4
    #dbg_declare(ptr %2, !23, !DIExpression(), !28)
  store ptr null, ptr %2, align 8, !dbg !28
    #dbg_declare(ptr %3, !29, !DIExpression(), !30)
  store ptr null, ptr %3, align 8, !dbg !30
  %4 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !31
  call void @clexma_log_malloc_result(ptr %4, ptr @0, i32 11, ptr @1), !dbg !32
  store ptr %4, ptr %3, align 8, !dbg !32
  %5 = load ptr, ptr %3, align 8, !dbg !33
  call void @free(ptr noundef %5) #5, !dbg !34
  %6 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !35
  call void @clexma_log_malloc_result(ptr %6, ptr @2, i32 13, ptr @3), !dbg !36
  store ptr %6, ptr %2, align 8, !dbg !36
  %7 = load ptr, ptr %2, align 8, !dbg !37
  %8 = load ptr, ptr %3, align 8, !dbg !39
  %9 = getelementptr inbounds %struct.T, ptr %8, i64 1, !dbg !40
  %10 = icmp eq ptr %7, %9, !dbg !41
  br i1 %10, label %11, label %13, !dbg !41

11:                                               ; preds = %0
  %12 = load ptr, ptr %2, align 8, !dbg !42
  call void @free(ptr noundef %12) #5, !dbg !44
  br label %13, !dbg !45

13:                                               ; preds = %11, %0
  ret i32 0, !dbg !46
}

; Function Attrs: nounwind allocsize(0)
declare noalias ptr @malloc(i64 noundef) #1

; Function Attrs: nounwind
declare void @free(ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_malloc_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !47 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !53, !DIExpression(), !54)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !55, !DIExpression(), !56)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !57, !DIExpression(), !58)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !59, !DIExpression(), !60)
  %9 = load ptr, ptr %5, align 8, !dbg !61
  %10 = load ptr, ptr %6, align 8, !dbg !62
  %11 = load i32, ptr %7, align 4, !dbg !63
  %12 = load ptr, ptr %8, align 8, !dbg !64
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !65
  ret void, !dbg !66
}

declare i32 @printf(ptr noundef, ...) #3

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind allocsize(0) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind allocsize(0) }
attributes #5 = { nounwind }

!llvm.dbg.cu = !{!7}
!llvm.module.flags = !{!10, !11, !12, !13, !14, !15, !16}
!llvm.ident = !{!17}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 23, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "f237d11b0289e2eecf830e52473e8071")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 576, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 72)
!7 = distinct !DICompileUnit(language: DW_LANG_C11, file: !8, producer: "clang version 21.0.0git (https://github.com/llvm/llvm-project.git d85685eb863641dce62a9f858ebcd6bab56c605b)", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, globals: !9, splitDebugInlining: false, nameTableKind: None)
!8 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "f237d11b0289e2eecf830e52473e8071")
!9 = !{!0}
!10 = !{i32 7, !"Dwarf Version", i32 5}
!11 = !{i32 2, !"Debug Info Version", i32 3}
!12 = !{i32 1, !"wchar_size", i32 4}
!13 = !{i32 8, !"PIC Level", i32 2}
!14 = !{i32 7, !"PIE Level", i32 2}
!15 = !{i32 7, !"uwtable", i32 2}
!16 = !{i32 7, !"frame-pointer", i32 2}
!17 = !{!"clang version 21.0.0git (https://github.com/llvm/llvm-project.git d85685eb863641dce62a9f858ebcd6bab56c605b)"}
!18 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 5, type: !19, scopeLine: 5, spFlags: DISPFlagDefinition, unit: !7, retainedNodes: !22)
!19 = !DISubroutineType(types: !20)
!20 = !{!21}
!21 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!22 = !{}
!23 = !DILocalVariable(name: "x", scope: !18, file: !2, line: 9, type: !24)
!24 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !25, size: 64)
!25 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "T", scope: !18, file: !2, line: 6, size: 64, elements: !26)
!26 = !{!27}
!27 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !25, file: !2, line: 7, baseType: !24, size: 64)
!28 = !DILocation(line: 9, column: 15, scope: !18)
!29 = !DILocalVariable(name: "y", scope: !18, file: !2, line: 10, type: !24)
!30 = !DILocation(line: 10, column: 15, scope: !18)
!31 = !DILocation(line: 11, column: 9, scope: !18)
!32 = !DILocation(line: 11, column: 7, scope: !18)
!33 = !DILocation(line: 12, column: 10, scope: !18)
!34 = !DILocation(line: 12, column: 5, scope: !18)
!35 = !DILocation(line: 13, column: 9, scope: !18)
!36 = !DILocation(line: 13, column: 7, scope: !18)
!37 = !DILocation(line: 14, column: 9, scope: !38)
!38 = distinct !DILexicalBlock(scope: !18, file: !2, line: 14, column: 9)
!39 = !DILocation(line: 14, column: 14, scope: !38)
!40 = !DILocation(line: 14, column: 16, scope: !38)
!41 = !DILocation(line: 14, column: 11, scope: !38)
!42 = !DILocation(line: 16, column: 14, scope: !43)
!43 = distinct !DILexicalBlock(scope: !38, file: !2, line: 15, column: 5)
!44 = !DILocation(line: 16, column: 9, scope: !43)
!45 = !DILocation(line: 17, column: 5, scope: !43)
!46 = !DILocation(line: 18, column: 5, scope: !18)
!47 = distinct !DISubprogram(name: "clexma_log_malloc_result", scope: !2, file: !2, line: 22, type: !48, scopeLine: 22, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !7, retainedNodes: !22)
!48 = !DISubroutineType(types: !49)
!49 = !{null, !50, !51, !21, !51}
!50 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!51 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !52, size: 64)
!52 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !4)
!53 = !DILocalVariable(name: "ptr", arg: 1, scope: !47, file: !2, line: 22, type: !50)
!54 = !DILocation(line: 22, column: 37, scope: !47)
!55 = !DILocalVariable(name: "filename", arg: 2, scope: !47, file: !2, line: 22, type: !51)
!56 = !DILocation(line: 22, column: 54, scope: !47)
!57 = !DILocalVariable(name: "line", arg: 3, scope: !47, file: !2, line: 22, type: !21)
!58 = !DILocation(line: 22, column: 68, scope: !47)
!59 = !DILocalVariable(name: "varname", arg: 4, scope: !47, file: !2, line: 22, type: !51)
!60 = !DILocation(line: 22, column: 86, scope: !47)
!61 = !DILocation(line: 23, column: 88, scope: !47)
!62 = !DILocation(line: 23, column: 93, scope: !47)
!63 = !DILocation(line: 23, column: 103, scope: !47)
!64 = !DILocation(line: 23, column: 109, scope: !47)
!65 = !DILocation(line: 23, column: 5, scope: !47)
!66 = !DILocation(line: 24, column: 1, scope: !47)
