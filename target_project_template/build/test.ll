; ModuleID = '/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c'
source_filename = "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct.T = type { ptr }

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 !dbg !10 {
  %1 = alloca i32, align 4
  %2 = alloca ptr, align 8
  %3 = alloca ptr, align 8
  %4 = alloca ptr, align 8
  store i32 0, ptr %1, align 4
    #dbg_declare(ptr %2, !16, !DIExpression(), !21)
    #dbg_declare(ptr %3, !22, !DIExpression(), !23)
    #dbg_declare(ptr %4, !24, !DIExpression(), !25)
  %5 = call noalias ptr @malloc(i64 noundef 8) #3, !dbg !26
  store ptr %5, ptr %3, align 8, !dbg !27
  %6 = call noalias ptr @malloc(i64 noundef 8) #3, !dbg !28
  store ptr %6, ptr %2, align 8, !dbg !29
  %7 = load ptr, ptr %2, align 8, !dbg !30
  store ptr %7, ptr %4, align 8, !dbg !31
  %8 = load ptr, ptr %2, align 8, !dbg !32
  store ptr %8, ptr %3, align 8, !dbg !33
  %9 = load ptr, ptr %2, align 8, !dbg !34
  %10 = load ptr, ptr %3, align 8, !dbg !36
  %11 = getelementptr inbounds %struct.T, ptr %10, i64 1, !dbg !37
  %12 = icmp eq ptr %9, %11, !dbg !38
  br i1 %12, label %13, label %15, !dbg !38

13:                                               ; preds = %0
  %14 = load ptr, ptr %2, align 8, !dbg !39
  call void @free(ptr noundef %14) #4, !dbg !41
  br label %15, !dbg !42

15:                                               ; preds = %13, %0
  ret i32 0, !dbg !43
}

; Function Attrs: nounwind allocsize(0)
declare noalias ptr @malloc(i64 noundef) #1

; Function Attrs: nounwind
declare void @free(ptr noundef) #2

attributes #0 = { noinline nounwind optnone uwtable "frame-pointer"="all" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { nounwind allocsize(0) "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { nounwind "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cmov,+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #3 = { nounwind allocsize(0) }
attributes #4 = { nounwind }

!llvm.dbg.cu = !{!0}
!llvm.module.flags = !{!2, !3, !4, !5, !6, !7, !8}
!llvm.ident = !{!9}

!0 = distinct !DICompileUnit(language: DW_LANG_C11, file: !1, producer: "clang version 21.0.0git", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, splitDebugInlining: false, nameTableKind: None)
!1 = !DIFile(filename: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template/src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "ae6da2a73799eaf7d51cdb565107c233")
!2 = !{i32 7, !"Dwarf Version", i32 5}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{i32 1, !"wchar_size", i32 4}
!5 = !{i32 8, !"PIC Level", i32 2}
!6 = !{i32 7, !"PIE Level", i32 2}
!7 = !{i32 7, !"uwtable", i32 2}
!8 = !{i32 7, !"frame-pointer", i32 2}
!9 = !{!"clang version 21.0.0git"}
!10 = distinct !DISubprogram(name: "main", scope: !11, file: !11, line: 5, type: !12, scopeLine: 5, spFlags: DISPFlagDefinition, unit: !0, retainedNodes: !15)
!11 = !DIFile(filename: "src/test.c", directory: "/home/clexma/Desktop/fox3/llvm_passes/target_project_template", checksumkind: CSK_MD5, checksum: "ae6da2a73799eaf7d51cdb565107c233")
!12 = !DISubroutineType(types: !13)
!13 = !{!14}
!14 = !DIBasicType(name: "int", size: 32, encoding: DW_ATE_signed)
!15 = !{}
!16 = !DILocalVariable(name: "x", scope: !10, file: !11, line: 9, type: !17)
!17 = !DIDerivedType(tag: DW_TAG_pointer_type, baseType: !18, size: 64)
!18 = distinct !DICompositeType(tag: DW_TAG_structure_type, name: "T", scope: !10, file: !11, line: 6, size: 64, elements: !19)
!19 = !{!20}
!20 = !DIDerivedType(tag: DW_TAG_member, name: "next", scope: !18, file: !11, line: 7, baseType: !17, size: 64)
!21 = !DILocation(line: 9, column: 15, scope: !10)
!22 = !DILocalVariable(name: "y", scope: !10, file: !11, line: 10, type: !17)
!23 = !DILocation(line: 10, column: 15, scope: !10)
!24 = !DILocalVariable(name: "z", scope: !10, file: !11, line: 11, type: !17)
!25 = !DILocation(line: 11, column: 15, scope: !10)
!26 = !DILocation(line: 12, column: 9, scope: !10)
!27 = !DILocation(line: 12, column: 7, scope: !10)
!28 = !DILocation(line: 13, column: 9, scope: !10)
!29 = !DILocation(line: 13, column: 7, scope: !10)
!30 = !DILocation(line: 15, column: 9, scope: !10)
!31 = !DILocation(line: 15, column: 7, scope: !10)
!32 = !DILocation(line: 16, column: 9, scope: !10)
!33 = !DILocation(line: 16, column: 7, scope: !10)
!34 = !DILocation(line: 18, column: 9, scope: !35)
!35 = distinct !DILexicalBlock(scope: !10, file: !11, line: 18, column: 9)
!36 = !DILocation(line: 18, column: 14, scope: !35)
!37 = !DILocation(line: 18, column: 16, scope: !35)
!38 = !DILocation(line: 18, column: 11, scope: !35)
!39 = !DILocation(line: 20, column: 14, scope: !40)
!40 = distinct !DILexicalBlock(scope: !35, file: !11, line: 19, column: 5)
!41 = !DILocation(line: 20, column: 9, scope: !40)
!42 = !DILocation(line: 21, column: 5, scope: !40)
!43 = !DILocation(line: 22, column: 5, scope: !10)
