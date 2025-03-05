; ModuleID = '/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c'
source_filename = "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.T = type { ptr }

@.str = private unnamed_addr constant [71 x i8] c"[OBJ ALLOC] malloc result: %p, in file: %s, at line: %d, variable: %s\0A\00", align 1, !dbg !0
@.str.1 = private unnamed_addr constant [78 x i8] c"[OBJ FREE] free result: %p freed, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !7
@.str.2 = private unnamed_addr constant [72 x i8] c"[AFTER FREE] freed ptr: %p, in file %s, at line %d, variable freed: %s\0A\00", align 1, !dbg !12

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !28 {
  %1 = alloca i32, align 4
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  store i32 0, ptr %1, align 4
    #dbg_declare(ptr %2, !33, !DIExpression(), !38)
  store ptr null, ptr %2, align 8, !dbg !38
    #dbg_declare(ptr %3, !39, !DIExpression(), !40)
  store ptr null, ptr %3, align 8, !dbg !40
  %4 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !41
  store ptr %4, ptr %3, align 8, !dbg !42
  %5 = load ptr, ptr %3, align 8, !dbg !43
  call void @free(ptr noundef %5) #5, !dbg !44
  %6 = call noalias ptr @malloc(i64 noundef 8) #4, !dbg !45
  store ptr %6, ptr %2, align 8, !dbg !46
  %7 = load ptr, ptr %2, align 8, !dbg !47
  %8 = load ptr, ptr %3, align 8, !dbg !49
  %9 = getelementptr inbounds %struct.T, ptr %8, i64 1, !dbg !50
  %10 = icmp eq ptr %7, %9, !dbg !51
  br i1 %10, label %11, label %13, !dbg !51

11:                                               ; preds = %0
  %12 = load ptr, ptr %2, align 8, !dbg !52
  call void @free(ptr noundef %12) #5, !dbg !54
  br label %13, !dbg !55

13:                                               ; preds = %11, %0
  ret i32 0, !dbg !56
}

; Function Attrs: nounwind allocsize(0)
declare noalias ptr @malloc(i64 noundef) #1

; Function Attrs: nounwind
declare void @free(ptr noundef) #2

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_malloc_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !57 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !63, !DIExpression(), !64)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !65, !DIExpression(), !66)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !67, !DIExpression(), !68)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !69, !DIExpression(), !70)
  %9 = load ptr, ptr %5, align 8, !dbg !71
  %10 = load ptr, ptr %6, align 8, !dbg !72
  %11 = load i32, ptr %7, align 4, !dbg !73
  %12 = load ptr, ptr %8, align 8, !dbg !74
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !75
  ret void, !dbg !76
}

declare i32 @printf(ptr noundef, ...) #3

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_before_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !77 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !78, !DIExpression(), !79)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !80, !DIExpression(), !81)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !82, !DIExpression(), !83)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !84, !DIExpression(), !85)
  %9 = load ptr, ptr %5, align 8, !dbg !86
  %10 = load ptr, ptr %6, align 8, !dbg !87
  %11 = load i32, ptr %7, align 4, !dbg !88
  %12 = load ptr, ptr %8, align 8, !dbg !89
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.1, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !90
  ret void, !dbg !91
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local void @clexma_log_after_free_result(ptr noundef %0, ptr noundef %1, i32 noundef %2, ptr noundef %3) #0 !dbg !92 {
  %5 = alloca ptr, align 8
  %6 = alloca ptr, align 8
  %7 = alloca i32, align 4
  %8 = alloca ptr, align 8
  store ptr %0, ptr %5, align 8
    #dbg_declare(ptr %5, !93, !DIExpression(), !94)
  store ptr %1, ptr %6, align 8
    #dbg_declare(ptr %6, !95, !DIExpression(), !96)
  store i32 %2, ptr %7, align 4
    #dbg_declare(ptr %7, !97, !DIExpression(), !98)
  store ptr %3, ptr %8, align 8
    #dbg_declare(ptr %8, !99, !DIExpression(), !100)
  %9 = load ptr, ptr %5, align 8, !dbg !101
  %10 = load ptr, ptr %6, align 8, !dbg !102
  %11 = load i32, ptr %7, align 4, !dbg !103
  %12 = load ptr, ptr %8, align 8, !dbg !104
  %13 = call i32 (ptr, ...) @printf(ptr noundef @.str.2, ptr noundef %9, ptr noundef %10, i32 noundef %11, ptr noundef %12), !dbg !105
  ret void, !dbg !106
}

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind allocsize(0) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { nounwind allocsize(0) }
attributes #5 = { nounwind }

!llvm.dbg.cu = !{!17}
!llvm.module.flags = !{!20, !21, !22, !23, !24, !25, !26}
!llvm.ident = !{!27}

!0 = !DIGlobalVariableExpression(var: !1, expr: !DIExpression())
!1 = distinct !DIGlobalVariable(scope: null, file: !2, line: 23, type: !3, isLocal: true, isDefinition: true)
!2 = !DIFile(filename: "src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "1645b73660ba0cae737e5bbdf0bf21ac")
!3 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 568, elements: !5)
!4 = !DIBasicType(name: "char", size: 8, encoding: DW_ATE_signed_char)
!5 = !{!6}
!6 = !DISubrange(count: 71)
!7 = !DIGlobalVariableExpression(var: !8, expr: !DIExpression())
!8 = distinct !DIGlobalVariable(scope: null, file: !2, line: 27, type: !9, isLocal: true, isDefinition: true)
!9 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 624, elements: !10)
!10 = !{!11}
!11 = !DISubrange(count: 78)
!12 = !DIGlobalVariableExpression(var: !13, expr: !DIExpression())
!13 = distinct !DIGlobalVariable(scope: null, file: !2, line: 31, type: !14, isLocal: true, isDefinition: true)
!14 = !DICompositeType(tag: DW_TAG_array_type, baseType: !4, size: 576, elements: !15)
!15 = !{!16}
!16 = !DISubrange(count: 72)
!17 = distinct !DICompileUnit(language: DW_LANG_C11, file: !18, producer: "clang version 21.0.0git", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, globals: !19, splitDebugInlining: false, nameTableKind: None)
!18 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "1645b73660ba0cae737e5bbdf0bf21ac")
!19 = !{!0, !7, !12}
!20 = !{i32 7, !"Dwarf Version", i32 5}
!21 = !{i32 2, !"Debug Info Version", i32 3}
!22 = !{i32 1, !"wchar_size", i32 4}
!23 = !{i32 8, !"PIC Level", i32 2}
!24 = !{i32 7, !"PIE Level", i32 2}
!25 = !{i32 7, !"uwtable", i32 2}
!26 = !{i32 7, !"frame-pointer", i32 2}
!27 = !{!"clang version 21.0.0git"}
!28 = distinct !DISubprogram(name: "main", scope: !2, file: !2, line: 5, type: !29, scopeLine: 5, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!29 = !DISubroutineType(types: !30)
!30 = !{!31}
!31 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!32 = !{}
!33 = !DILocalVariable(name: "x", scope: !28, file: !2, line: 9, type: !34)
!34 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !35, size: 64)
!35 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "T", scope: !28, file: !2, line: 6, size: 64, elements: !36)
!36 = !{!37}
!37 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !35, file: !2, line: 7, baseType: !34, size: 64)
!38 = !DILocation(line: 9, column: 15, scope: !28)
!39 = !DILocalVariable(name: "y", scope: !28, file: !2, line: 10, type: !34)
!40 = !DILocation(line: 10, column: 15, scope: !28)
!41 = !DILocation(line: 11, column: 9, scope: !28)
!42 = !DILocation(line: 11, column: 7, scope: !28)
!43 = !DILocation(line: 12, column: 10, scope: !28)
!44 = !DILocation(line: 12, column: 5, scope: !28)
!45 = !DILocation(line: 13, column: 9, scope: !28)
!46 = !DILocation(line: 13, column: 7, scope: !28)
!47 = !DILocation(line: 14, column: 9, scope: !48)
!48 = distinct !DILexicalBlock(scope: !28, file: !2, line: 14, column: 9)
!49 = !DILocation(line: 14, column: 14, scope: !48)
!50 = !DILocation(line: 14, column: 16, scope: !48)
!51 = !DILocation(line: 14, column: 11, scope: !48)
!52 = !DILocation(line: 16, column: 14, scope: !53)
!53 = distinct !DILexicalBlock(scope: !48, file: !2, line: 15, column: 5)
!54 = !DILocation(line: 16, column: 9, scope: !53)
!55 = !DILocation(line: 17, column: 5, scope: !53)
!56 = !DILocation(line: 18, column: 5, scope: !28)
!57 = distinct !DISubprogram(name: "clexma_log_malloc_result", scope: !2, file: !2, line: 22, type: !58, scopeLine: 22, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!58 = !DISubroutineType(types: !59)
!59 = !{null, !60, !61, !31, !61}
!60 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: null, size: 64)
!61 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !62, size: 64)
!62 = !DIDerivedType(tag: DW_TAG_const_type, baseType: !4)
!63 = !DILocalVariable(name: "ptr", arg: 1, scope: !57, file: !2, line: 22, type: !60)
!64 = !DILocation(line: 22, column: 37, scope: !57)
!65 = !DILocalVariable(name: "filename", arg: 2, scope: !57, file: !2, line: 22, type: !61)
!66 = !DILocation(line: 22, column: 54, scope: !57)
!67 = !DILocalVariable(name: "line", arg: 3, scope: !57, file: !2, line: 22, type: !31)
!68 = !DILocation(line: 22, column: 68, scope: !57)
!69 = !DILocalVariable(name: "varname", arg: 4, scope: !57, file: !2, line: 22, type: !61)
!70 = !DILocation(line: 22, column: 86, scope: !57)
!71 = !DILocation(line: 23, column: 87, scope: !57)
!72 = !DILocation(line: 23, column: 92, scope: !57)
!73 = !DILocation(line: 23, column: 102, scope: !57)
!74 = !DILocation(line: 23, column: 108, scope: !57)
!75 = !DILocation(line: 23, column: 5, scope: !57)
!76 = !DILocation(line: 24, column: 1, scope: !57)
!77 = distinct !DISubprogram(name: "clexma_log_before_free_result", scope: !2, file: !2, line: 26, type: !58, scopeLine: 26, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!78 = !DILocalVariable(name: "ptr", arg: 1, scope: !77, file: !2, line: 26, type: !60)
!79 = !DILocation(line: 26, column: 42, scope: !77)
!80 = !DILocalVariable(name: "filename", arg: 2, scope: !77, file: !2, line: 26, type: !61)
!81 = !DILocation(line: 26, column: 59, scope: !77)
!82 = !DILocalVariable(name: "line", arg: 3, scope: !77, file: !2, line: 26, type: !31)
!83 = !DILocation(line: 26, column: 73, scope: !77)
!84 = !DILocalVariable(name: "varname", arg: 4, scope: !77, file: !2, line: 26, type: !61)
!85 = !DILocation(line: 26, column: 91, scope: !77)
!86 = !DILocation(line: 27, column: 94, scope: !77)
!87 = !DILocation(line: 27, column: 99, scope: !77)
!88 = !DILocation(line: 27, column: 109, scope: !77)
!89 = !DILocation(line: 27, column: 115, scope: !77)
!90 = !DILocation(line: 27, column: 5, scope: !77)
!91 = !DILocation(line: 28, column: 1, scope: !77)
!92 = distinct !DISubprogram(name: "clexma_log_after_free_result", scope: !2, file: !2, line: 30, type: !58, scopeLine: 30, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !17, retainedNodes: !32)
!93 = !DILocalVariable(name: "ptr", arg: 1, scope: !92, file: !2, line: 30, type: !60)
!94 = !DILocation(line: 30, column: 41, scope: !92)
!95 = !DILocalVariable(name: "filename", arg: 2, scope: !92, file: !2, line: 30, type: !61)
!96 = !DILocation(line: 30, column: 58, scope: !92)
!97 = !DILocalVariable(name: "line", arg: 3, scope: !92, file: !2, line: 30, type: !31)
!98 = !DILocation(line: 30, column: 72, scope: !92)
!99 = !DILocalVariable(name: "varname", arg: 4, scope: !92, file: !2, line: 30, type: !61)
!100 = !DILocation(line: 30, column: 90, scope: !92)
!101 = !DILocation(line: 31, column: 88, scope: !92)
!102 = !DILocation(line: 31, column: 93, scope: !92)
!103 = !DILocation(line: 31, column: 103, scope: !92)
!104 = !DILocation(line: 31, column: 109, scope: !92)
!105 = !DILocation(line: 31, column: 5, scope: !92)
!106 = !DILocation(line: 32, column: 1, scope: !92)
